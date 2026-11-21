/**
 * @file 
 * 
 * @note Automatically generated code by Model2CodeSynthesizer
 * (github.com/tomboro88/Model2CodeSynthesizer).
 */

#ifndef COMPONENTS_H
#define COMPONENTS_H

#ifdef  __cplusplus
extern "C" {
#endif

//Start of user code includes top
//End of user code
#    include "../umltest.h"
//Start of user code includes bottom
//End of user code

    /**
     * @brief The type representing the components_component6_s struct.
     */
    typedef struct components_component6_s \
            components_component6_t;

    /**
     * @brief The type representing the components_component7_s struct.
     */
    typedef struct components_component7_s \
            components_component7_t;

    /**
     * @brief The virtual table type for the components_iprovided_s struct.
     */
    typedef struct components_iprovided_vt_s \
            components_iprovided_vt_t;

    /**
     * @brief The type representing the components_iprovided_s struct.
     */
    typedef struct components_iprovided_s \
            components_iprovided_t;

    /**
     * @brief The virtual table type for the components_irequired_s struct.
     */
    typedef struct components_irequired_vt_s \
            components_irequired_vt_t;

    /**
     * @brief The type representing the components_irequired_s struct.
     */
    typedef struct components_irequired_s \
            components_irequired_t;

    /**
     */
    struct components_component6_s
    {
        /**
         */
        components_cprovided_t          Port1;
        /**
         */
        components_crequired_t          Port2;
    };
#error No constructor was defined for the Component6 class. 

    /**
     */
    struct components_component7_s
    {
        /**
         */
        components_crequireprovided_t   Port1;
    };
#error No constructor was defined for the Component7 class. 

    /**
     */
    struct components_iprovided_s
    {
        /**
         * @brief The pointer to the virtual table of the IProvided class.
         */
        const components_iprovided_vt_t* \
                                        p_vtable;
    };

    /**
     * @brief The virtual table struct for the components_iprovided_s struct.
     * Contains pointers to all virtual methods of the class.
     */
    struct components_iprovided_vt_s
    {
        /**
         * @param [in] p_obj The pointer to the self object.
         */
        void (*p_operation1)(components_iprovided_t* const p_obj);
        /**
         * @param [in] p_obj The pointer to the self object.
         */
        void (*p_operation2)(components_iprovided_t* const p_obj);
    };

    /**
     */
    struct components_irequired_s
    {
        /**
         * @brief The pointer to the virtual table of the IRequired class.
         */
        const components_irequired_vt_t* \
                                        p_vtable;
    };

    /**
     * @brief The virtual table struct for the components_irequired_s struct.
     * Contains pointers to all virtual methods of the class.
     */
    struct components_irequired_vt_s
    {
        /**
         * @param [in] p_obj The pointer to the self object.
         */
        void (*p_operation1)(components_irequired_t* const p_obj);
    };

    void components_iprovided_operation1(components_iprovided_t* const p_obj);
    void components_iprovided_operation2(components_iprovided_t* const p_obj);

    void components_irequired_operation1(components_irequired_t* const p_obj);

#ifdef  __cplusplus
}
#endif

#endif  /* COMPONENTS_H */

/*** end of file ***/
