/*=========================================================================
 *
 *  Copyright RTK Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#include "rtksart_ggo.h"
#include "rtkGgoFunctions.h"

#include "rtkThreeDCircularProjectionGeometryXMLFile.h"
#include "rtkSARTConeBeamReconstructionFilter.h"
#include "rtkNormalizedJosephBackProjectionImageFilter.h"
#ifdef RTK_USE_CUDA
  #include "itkCudaImage.h"
#endif

#include <itkImageFileWriter.h>

int main(int argc, char * argv[])
{
  GGO(rtksart, args_info);

  typedef float OutputPixelType;
  const unsigned int Dimension = 3;

#ifdef RTK_USE_CUDA
  typedef itk::CudaImage< OutputPixelType, Dimension > OutputImageType;
#else
  typedef itk::Image< OutputPixelType, Dimension > OutputImageType;
#endif

  // Projections reader
  typedef rtk::ProjectionsReader< OutputImageType > ReaderType;
  ReaderType::Pointer reader = ReaderType::New();
  rtk::SetProjectionsReaderFromGgo<ReaderType, args_info_rtksart>(reader, args_info);

  // Geometry
  if(args_info.verbose_flag)
    std::cout << "Reading geometry information from "
              << args_info.geometry_arg
              << "..."
              << std::endl;
  rtk::ThreeDCircularProjectionGeometryXMLFileReader::Pointer geometryReader;
  geometryReader = rtk::ThreeDCircularProjectionGeometryXMLFileReader::New();
  geometryReader->SetFilename(args_info.geometry_arg);
  TRY_AND_EXIT_ON_ITK_EXCEPTION( geometryReader->GenerateOutputInformation() )

  // Create input: either an existing volume read from a file or a blank image
  itk::ImageSource< OutputImageType >::Pointer inputFilter;
  if(args_info.input_given)
    {
    // Read an existing image to initialize the volume
    typedef itk::ImageFileReader<  OutputImageType > InputReaderType;
    InputReaderType::Pointer inputReader = InputReaderType::New();
    inputReader->SetFileName( args_info.input_arg );
    inputFilter = inputReader;
    }
  else
    {
    // Create new empty volume
    typedef rtk::ConstantImageSource< OutputImageType > ConstantImageSourceType;
    ConstantImageSourceType::Pointer constantImageSource = ConstantImageSourceType::New();
    rtk::SetConstantImageSourceFromGgo<ConstantImageSourceType, args_info_rtksart>(constantImageSource, args_info);
    inputFilter = constantImageSource;
    }

//  // Construct selected backprojection filter
//  rtk::BackProjectionImageFilter<OutputImageType, OutputImageType>::Pointer bp;
//  switch(args_info.bp_arg)
//  {
//  case(bp_arg_VoxelBasedBackProjection):
//    bp = rtk::BackProjectionImageFilter<OutputImageType, OutputImageType>::New();
//    break;
//  case(bp_arg_Joseph):
//    bp = rtk::NormalizedJosephBackProjectionImageFilter<OutputImageType, OutputImageType>::New();
//    break;
//  case(bp_arg_CudaVoxelBased):
//#ifdef RTK_USE_CUDA
//    bp = rtk::CudaBackProjectionImageFilter::New();
//#else
//    std::cerr << "The program has not been compiled with cuda option" << std::endl;
//    return EXIT_FAILURE;
//#endif
//    break;

//  default:
//    std::cerr << "Unhandled --bp value." << std::endl;
//    return EXIT_FAILURE;
//  }


//  switch(args_info.sart_arg)
//  {
//  case(sart_arg_Sart):
//    sart = rtk::SARTConeBeamReconstructionFilter<OutputImageType, OutputImageType>::New();
//    break;
//  case(bp_arg_Joseph):
//#ifdef RTK_USE_CUDA
//    sart = rtk::CudaSARTConeBeamReconstructionFilter::New();
//#else
//    std::cerr << "The program has not been compiled with cuda option" << std::endl;
//    return EXIT_FAILURE;
//#endif
//    break;

//  default:
//    std::cerr << "Unhandled --bp value." << std::endl;
//    return EXIT_FAILURE;
//  }

  // SART reconstruction filter
  rtk::SARTConeBeamReconstructionFilter< OutputImageType >::Pointer sart =
      rtk::SARTConeBeamReconstructionFilter< OutputImageType >::New();

  // Set the forward and back projection filters to be used inside admmFilter
  sart->SetForwardProjectionFilter(args_info.fp_arg);
  sart->SetBackProjectionFilter(args_info.bp_arg);

  sart->SetInput( inputFilter->GetOutput() );
  sart->SetInput(1, reader->GetOutput());
  sart->SetGeometry( geometryReader->GetOutputObject() );
  sart->SetNumberOfIterations( args_info.niterations_arg );
  sart->SetLambda( args_info.lambda_arg );

  itk::TimeProbe readerProbe;
  if(args_info.time_flag)
    {
    std::cout << "Recording elapsed time... " << std::flush;
    readerProbe.Start();
    }
  if(args_info.positivity_flag)
    {
    sart->SetEnforcePositivity(true);
    }

  TRY_AND_EXIT_ON_ITK_EXCEPTION( sart->Update() )

  if(args_info.time_flag)
    {
    sart->PrintTiming(std::cout);
    readerProbe.Stop();
    std::cout << "It took...  " << readerProbe.GetMean() << ' ' << readerProbe.GetUnit() << std::endl;
    }

  // Write
  typedef itk::ImageFileWriter< OutputImageType > WriterType;
  WriterType::Pointer writer = WriterType::New();
  writer->SetFileName( args_info.output_arg );
  writer->SetInput( sart->GetOutput() );
  TRY_AND_EXIT_ON_ITK_EXCEPTION( writer->Update() );

  return EXIT_SUCCESS;
}
