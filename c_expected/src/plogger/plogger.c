/**
 * @file 
 * 
 * @brief The plogger package source file.
 * 
 * @note Automatically generated code by Model2CodeSynthesizer
 * (github.com/tomboro88/Model2CodeSynthesizer).
 */

/*******************************************************************************
 *
 * Include statements.
 *
 ******************************************************************************/
//Start of user code includes top
//End of user code
#include "plogger.h"
//Start of user code includes bottom
//End of user code
/*******************************************************************************
 *
 * Data type, constant, and macro definitions.
 *
 ******************************************************************************/
/*******************************************************************************
 *
 * Non-private function prototypes.
 *
 ******************************************************************************/
/*******************************************************************************
 *
 * Private function prototypes.
 *
 ******************************************************************************/
/*******************************************************************************
 *
 * Static data declarations.
 *
 ******************************************************************************/
/*******************************************************************************
 *
 * Inline functions.
 *
 ******************************************************************************/
/*******************************************************************************
 *
 * Public function bodies.
 *
 ******************************************************************************/
/**
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_str A pointer to the string that will be logged.
 */
void
plogger_logger_record(plogger_logger_t* const p_obj, const char* const p_str)
{
    /*Code for handling a virtual operation.*/
    if((NULL != p_obj) && (NULL != p_obj->p_vtable))
    {
        void (*p_record)(plogger_logger_t* const p_obj, const char* const p_str)
            = p_obj->p_vtable->p_record;

        if(NULL != p_record)
        {
            p_record(p_obj, p_str);
        }
    }
}

/**
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_str A pointer to the string that will be logged.
 * @param [in] dbl_param A double parameter that will be logged.
 */
void
plogger_logger_record_dbl(plogger_logger_t* const p_obj,\
                          const char* const p_str, double const dbl_param)
{
    /*Code for handling a virtual operation.*/
    if((NULL != p_obj) && (NULL != p_obj->p_vtable))
    {
        void (*p_record_dbl)(plogger_logger_t* const p_obj,\
                             const char* const p_str, double const dbl_param)
            = p_obj->p_vtable->p_record_dbl;

        if(NULL != p_record_dbl)
        {
            p_record_dbl(p_obj, p_str, dbl_param);
        }
    }
}

/**
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_str A pointer to the string that will be logged.
 * @param [in] u16_param 
 * @param [in] char_param 
 */
void
plogger_logger_record_u16_char(plogger_logger_t* const p_obj,\
                               const char* const p_str,\
                               uint16_t const u16_param, char const char_param)
{
    /*Code for handling a virtual operation.*/
    if((NULL != p_obj) && (NULL != p_obj->p_vtable))
    {
        void (*p_record_u16_char)(plogger_logger_t* const p_obj,\
                                  const char* const p_str,\
                                  uint16_t const u16_param,\
                                  char const char_param)
            = p_obj->p_vtable->p_record_u16_char;

        if(NULL != p_record_u16_char)
        {
            p_record_u16_char(p_obj, p_str, u16_param, char_param);
        }
    }
}

/*******************************************************************************
 *
 * Non-public function bodies.
 *
 ******************************************************************************/
/*** end of file ***/
