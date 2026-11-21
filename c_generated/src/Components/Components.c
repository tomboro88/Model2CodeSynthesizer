/**
 * @file 
 * 
 * @brief The Components package source file.
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
#include "Components.h"
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
 */
void
components_iprovided_operation1(components_iprovided_t* const p_obj)
{
    /*Code for handling a virtual operation.*/
    if((NULL != p_obj) && (NULL != p_obj->p_vtable))
    {
        void (*p_operation1)(components_iprovided_t* const p_obj)
            = p_obj->p_vtable->p_operation1;

        if(NULL != p_operation1)
        {
            p_operation1(p_obj);
        }
    }
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
components_iprovided_operation2(components_iprovided_t* const p_obj)
{
    /*Code for handling a virtual operation.*/
    if((NULL != p_obj) && (NULL != p_obj->p_vtable))
    {
        void (*p_operation2)(components_iprovided_t* const p_obj)
            = p_obj->p_vtable->p_operation2;

        if(NULL != p_operation2)
        {
            p_operation2(p_obj);
        }
    }
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
void
components_irequired_operation1(components_irequired_t* const p_obj)
{
    /*Code for handling a virtual operation.*/
    if((NULL != p_obj) && (NULL != p_obj->p_vtable))
    {
        void (*p_operation1)(components_irequired_t* const p_obj)
            = p_obj->p_vtable->p_operation1;

        if(NULL != p_operation1)
        {
            p_operation1(p_obj);
        }
    }
}

/*******************************************************************************
 *
 * Non-public function bodies.
 *
 ******************************************************************************/
/*** end of file ***/
