/** @file rtkfdk_ggo.h
 *  @brief The header file for the command line option parser
 *  generated by GNU Gengetopt version 2.22.4
 *  http://www.gnu.org/software/gengetopt.
 *  DO NOT modify this file, since it can be overwritten
 *  @author GNU Gengetopt by Lorenzo Bettini */

#ifndef RTKFDK_GGO_H
#define RTKFDK_GGO_H

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h> /* for FILE */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef CMDLINE_PARSER_RTKFDK_PACKAGE
/** @brief the program name (used for printing errors) */
#define CMDLINE_PARSER_RTKFDK_PACKAGE "rtk"
#endif

#ifndef CMDLINE_PARSER_RTKFDK_PACKAGE_NAME
/** @brief the complete program name (used for help and version) */
#define CMDLINE_PARSER_RTKFDK_PACKAGE_NAME "rtk"
#endif

#ifndef CMDLINE_PARSER_RTKFDK_VERSION
/** @brief the program version */
#define CMDLINE_PARSER_RTKFDK_VERSION "Reconstruct a 3D volume from a sequence of projections [Feldkamp, David, Kress, 1984]."
#endif

/** @brief Where the command line options are stored */
struct args_info_rtkfdk
{
  const char *help_help; /**< @brief Print help and exit help description.  */
  const char *version_help; /**< @brief Print version and exit help description.  */
  int verbose_flag;	/**< @brief Verbose execution (default=off).  */
  const char *verbose_help; /**< @brief Verbose execution help description.  */
  char * config_arg;	/**< @brief Config file.  */
  char * config_orig;	/**< @brief Config file original value given at command line.  */
  const char *config_help; /**< @brief Config file help description.  */
  char * geometry_arg;	/**< @brief XML geometry file name.  */
  char * geometry_orig;	/**< @brief XML geometry file name original value given at command line.  */
  const char *geometry_help; /**< @brief XML geometry file name help description.  */
  char * path_arg;	/**< @brief Path containing projections.  */
  char * path_orig;	/**< @brief Path containing projections original value given at command line.  */
  const char *path_help; /**< @brief Path containing projections help description.  */
  char * regexp_arg;	/**< @brief Regular expression to select projection files in path.  */
  char * regexp_orig;	/**< @brief Regular expression to select projection files in path original value given at command line.  */
  const char *regexp_help; /**< @brief Regular expression to select projection files in path help description.  */
  char * output_arg;	/**< @brief Output file name.  */
  char * output_orig;	/**< @brief Output file name original value given at command line.  */
  const char *output_help; /**< @brief Output file name help description.  */
  char * hardware_arg;	/**< @brief Hardware used for computation (default='cpu').  */
  char * hardware_orig;	/**< @brief Hardware used for computation original value given at command line.  */
  const char *hardware_help; /**< @brief Hardware used for computation help description.  */
  int lowmem_flag;	/**< @brief Load only one projection per thread in memory (default=off).  */
  const char *lowmem_help; /**< @brief Load only one projection per thread in memory help description.  */
  int divisions_arg;	/**< @brief Number of stream divisions to cope with large CTs (default='1').  */
  char * divisions_orig;	/**< @brief Number of stream divisions to cope with large CTs original value given at command line.  */
  const char *divisions_help; /**< @brief Number of stream divisions to cope with large CTs help description.  */
  double pad_arg;	/**< @brief Data padding parameter to correct for truncation (default='0.0').  */
  char * pad_orig;	/**< @brief Data padding parameter to correct for truncation original value given at command line.  */
  const char *pad_help; /**< @brief Data padding parameter to correct for truncation help description.  */
  double hann_arg;	/**< @brief Cut frequency for hann window in ]0,1] (0.0 disables it) (default='0.0').  */
  char * hann_orig;	/**< @brief Cut frequency for hann window in ]0,1] (0.0 disables it) original value given at command line.  */
  const char *hann_help; /**< @brief Cut frequency for hann window in ]0,1] (0.0 disables it) help description.  */
  double* origin_arg;	/**< @brief Origin (default=centered).  */
  char ** origin_orig;	/**< @brief Origin (default=centered) original value given at command line.  */
  unsigned int origin_min; /**< @brief Origin (default=centered)'s minimum occurreces */
  unsigned int origin_max; /**< @brief Origin (default=centered)'s maximum occurreces */
  const char *origin_help; /**< @brief Origin (default=centered) help description.  */
  int* dimension_arg;	/**< @brief Dimension (default='256').  */
  char ** dimension_orig;	/**< @brief Dimension original value given at command line.  */
  unsigned int dimension_min; /**< @brief Dimension's minimum occurreces */
  unsigned int dimension_max; /**< @brief Dimension's maximum occurreces */
  const char *dimension_help; /**< @brief Dimension help description.  */
  double* spacing_arg;	/**< @brief Spacing (default='1').  */
  char ** spacing_orig;	/**< @brief Spacing original value given at command line.  */
  unsigned int spacing_min; /**< @brief Spacing's minimum occurreces */
  unsigned int spacing_max; /**< @brief Spacing's maximum occurreces */
  const char *spacing_help; /**< @brief Spacing help description.  */
  
  unsigned int help_given ;	/**< @brief Whether help was given.  */
  unsigned int version_given ;	/**< @brief Whether version was given.  */
  unsigned int verbose_given ;	/**< @brief Whether verbose was given.  */
  unsigned int config_given ;	/**< @brief Whether config was given.  */
  unsigned int geometry_given ;	/**< @brief Whether geometry was given.  */
  unsigned int path_given ;	/**< @brief Whether path was given.  */
  unsigned int regexp_given ;	/**< @brief Whether regexp was given.  */
  unsigned int output_given ;	/**< @brief Whether output was given.  */
  unsigned int hardware_given ;	/**< @brief Whether hardware was given.  */
  unsigned int lowmem_given ;	/**< @brief Whether lowmem was given.  */
  unsigned int divisions_given ;	/**< @brief Whether divisions was given.  */
  unsigned int pad_given ;	/**< @brief Whether pad was given.  */
  unsigned int hann_given ;	/**< @brief Whether hann was given.  */
  unsigned int origin_given ;	/**< @brief Whether origin was given.  */
  unsigned int dimension_given ;	/**< @brief Whether dimension was given.  */
  unsigned int spacing_given ;	/**< @brief Whether spacing was given.  */

  char **inputs ; /**< @brief unamed options (options without names) */
  unsigned inputs_num ; /**< @brief unamed options number */
} ;

/** @brief The additional parameters to pass to parser functions */
struct cmdline_parser_rtkfdk_params
{
  int override; /**< @brief whether to override possibly already present options (default 0) */
  int initialize; /**< @brief whether to initialize the option structure args_info_rtkfdk (default 1) */
  int check_required; /**< @brief whether to check that all required options were provided (default 1) */
  int check_ambiguity; /**< @brief whether to check for options already specified in the option structure args_info_rtkfdk (default 0) */
  int print_errors; /**< @brief whether getopt_long should print an error message for a bad option (default 1) */
} ;

/** @brief the purpose string of the program */
extern const char *args_info_rtkfdk_purpose;
/** @brief the usage string of the program */
extern const char *args_info_rtkfdk_usage;
/** @brief all the lines making the help output */
extern const char *args_info_rtkfdk_help[];

/**
 * The command line parser
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_rtkfdk (int argc, char **argv,
  struct args_info_rtkfdk *args_info);

/**
 * The command line parser (version with additional parameters - deprecated)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param override whether to override possibly already present options
 * @param initialize whether to initialize the option structure my_args_info
 * @param check_required whether to check that all required options were provided
 * @return 0 if everything went fine, NON 0 if an error took place
 * @deprecated use cmdline_parser_rtkfdk_ext() instead
 */
int cmdline_parser_rtkfdk2 (int argc, char **argv,
  struct args_info_rtkfdk *args_info,
  int override, int initialize, int check_required);

/**
 * The command line parser (version with additional parameters)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param params additional parameters for the parser
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_rtkfdk_ext (int argc, char **argv,
  struct args_info_rtkfdk *args_info,
  struct cmdline_parser_rtkfdk_params *params);

/**
 * Save the contents of the option struct into an already open FILE stream.
 * @param outfile the stream where to dump options
 * @param args_info the option struct to dump
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_rtkfdk_dump(FILE *outfile,
  struct args_info_rtkfdk *args_info);

/**
 * Save the contents of the option struct into a (text) file.
 * This file can be read by the config file parser (if generated by gengetopt)
 * @param filename the file where to save
 * @param args_info the option struct to save
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_rtkfdk_file_save(const char *filename,
  struct args_info_rtkfdk *args_info);

/**
 * Print the help
 */
void cmdline_parser_rtkfdk_print_help(void);
/**
 * Print the version
 */
void cmdline_parser_rtkfdk_print_version(void);

/**
 * Initializes all the fields a cmdline_parser_rtkfdk_params structure 
 * to their default values
 * @param params the structure to initialize
 */
void cmdline_parser_rtkfdk_params_init(struct cmdline_parser_rtkfdk_params *params);

/**
 * Allocates dynamically a cmdline_parser_rtkfdk_params structure and initializes
 * all its fields to their default values
 * @return the created and initialized cmdline_parser_rtkfdk_params structure
 */
struct cmdline_parser_rtkfdk_params *cmdline_parser_rtkfdk_params_create(void);

/**
 * Initializes the passed args_info_rtkfdk structure's fields
 * (also set default values for options that have a default)
 * @param args_info the structure to initialize
 */
void cmdline_parser_rtkfdk_init (struct args_info_rtkfdk *args_info);
/**
 * Deallocates the string fields of the args_info_rtkfdk structure
 * (but does not deallocate the structure itself)
 * @param args_info the structure to deallocate
 */
void cmdline_parser_rtkfdk_free (struct args_info_rtkfdk *args_info);

/**
 * The config file parser (deprecated version)
 * @param filename the name of the config file
 * @param args_info the structure where option information will be stored
 * @param override whether to override possibly already present options
 * @param initialize whether to initialize the option structure my_args_info
 * @param check_required whether to check that all required options were provided
 * @return 0 if everything went fine, NON 0 if an error took place
 * @deprecated use cmdline_parser_rtkfdk_config_file() instead
 */
int cmdline_parser_rtkfdk_configfile (const char *filename,
  struct args_info_rtkfdk *args_info,
  int override, int initialize, int check_required);

/**
 * The config file parser
 * @param filename the name of the config file
 * @param args_info the structure where option information will be stored
 * @param params additional parameters for the parser
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_rtkfdk_config_file (const char *filename,
  struct args_info_rtkfdk *args_info,
  struct cmdline_parser_rtkfdk_params *params);

/**
 * Checks that all the required options were specified
 * @param args_info the structure to check
 * @param prog_name the name of the program that will be used to print
 *   possible errors
 * @return
 */
int cmdline_parser_rtkfdk_required (struct args_info_rtkfdk *args_info,
  const char *prog_name);

extern const char *cmdline_parser_rtkfdk_hardware_values[];  /**< @brief Possible values for hardware. */


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* RTKFDK_GGO_H */
