/**
 * @file 
 * 
 * @note Automatically generated code by Model2CodeSynthesizer
 * (github.com/tomboro88/Model2CodeSynthesizer).
 */

#ifndef PLOGGER_H
#define PLOGGER_H

#ifdef  __cplusplus
extern "C" {
#endif

//Start of user code includes top
//End of user code
#    include "../umltest.h"
#    include <stdint.h>
//Start of user code includes bottom
//End of user code

    /**
     * @brief The virtual table type for the plogger_logger_s struct.
     */
    typedef struct plogger_logger_vt_s \
            plogger_logger_vt_t;

    /**
     * @brief The type representing the plogger_logger_s struct.
     */
    typedef struct plogger_logger_s \
            plogger_logger_t;

    /**
     * @brief This is an example logging functionality modelled as an Interface,
     * providing dynamic dependency injection.
     * @details It can easily be replaced with different functionalities just by
     * replacing proper virtual table with function pointers. For example this
     * example project will use puts function, but unit tests will use some
     * custom function used for verifying the correct operation of the code.
     */
    struct plogger_logger_s
    {
        /**
         * @brief The pointer to the virtual table of the logger class.
         */
        const plogger_logger_vt_t*      p_vtable;
    };

    /**
     * @brief The virtual table struct for the plogger_logger_s struct. Contains
     * pointers to all virtual methods of the class.
     */
    struct plogger_logger_vt_s
    {
        /**
         * @param [in] p_obj The pointer to the self object.
         * @param [in] p_str A pointer to the string that will be logged.
         */
        void (*p_record)(plogger_logger_t* const p_obj,\
                         const char* const p_str);
        /**
         * @param [in] p_obj The pointer to the self object.
         * @param [in] p_str A pointer to the string that will be logged.
         * @param [in] dbl_param A double parameter that will be logged.
         */
        void (*p_record_dbl)(plogger_logger_t* const p_obj,\
                             const char* const p_str, double const dbl_param);
        /**
         * @param [in] p_obj The pointer to the self object.
         * @param [in] p_str A pointer to the string that will be logged.
         * @param [in] u16_param 
         * @param [in] char_param 
         */
        void (*p_record_u16_char)(plogger_logger_t* const p_obj,\
                                  const char* const p_str,\
                                  uint16_t const u16_param,\
                                  char const char_param);
    };

    void plogger_logger_record(plogger_logger_t* const p_obj,\
                               const char* const p_str);
    void plogger_logger_record_dbl(plogger_logger_t* const p_obj,\
                                   const char* const p_str,\
                                   double const dbl_param);
    void plogger_logger_record_u16_char(plogger_logger_t* const p_obj,\
                                        const char* const p_str,\
                                        uint16_t const u16_param,\
                                        char const char_param);

#ifdef  __cplusplus
}
#endif

#endif  /* PLOGGER_H */

/*** end of file ***/
