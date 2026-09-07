/**
 * @file 
 * 
 * @brief The Tkind package source file.
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
#include "Tkind.h"
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
//Start of user code includes bottom
#include <stdio.h>
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
void tkind_cbase1_set_uint_default(tkind_cbase1_t* const p_obj,\
                                   uint32_t const param1);

void tkind_ctest_set_uint_incr(tkind_cbase1_t* const p_obj,\
                               uint32_t const param1);

/*******************************************************************************
 *
 * Private function prototypes.
 *
 ******************************************************************************/
static void tkind_cbase1_init_df(tkind_cbase1_t* const p_obj);

static float tkind_cbase2_get_flt_dflt(tkind_cbase2_t* const p_obj);

static void tkind_cbase2_init_df(tkind_cbase2_t* const p_obj);

static void tkind_ctest_start_sm1(tkind_ctest_t* const p_obj);

static float tkind_ctest_get_flt_from_uint(tkind_cbase2_t* const p_obj);

static void tkind_ctest_init_df(tkind_ctest_t* const p_obj);

static void tkind_sm1_rec_log(tkind_sm1_t* const p_obj,\
                              const char* const p_str);

static void tkind_sm1_init_df(tkind_sm1_t* const p_obj);

static void tkind_sm1_exit_region2(tkind_sm1_t* const p_obj);
static void tkind_sm1_exit_region3(tkind_sm1_t* const p_obj);
static void tkind_sm1_exit_region4(tkind_sm1_t* const p_obj);
static void tkind_sm1_exit_region5(tkind_sm1_t* const p_obj);
static void tkind_sm1_exit_region6(tkind_sm1_t* const p_obj);

static sm_event_status_t tkind_sm1_dispatch_a(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_b(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_c(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_d(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_e(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_f(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_g(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_h(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_i(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_j(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_k(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_l(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_m(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_n(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_o(tkind_sm1_t* const p_obj);

static sm_event_status_t tkind_sm1_dispatch_a_region2(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_b_region2(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_c_region2(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_d_region2(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_e_region2(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_f_region2(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_g_region2(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_h_region2(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_n_region2(tkind_sm1_t* const p_obj);

static sm_event_status_t tkind_sm1_dispatch_d_region3(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_e_region3(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_n_region3(tkind_sm1_t* const p_obj);

static sm_event_status_t tkind_sm1_dispatch_g_region4(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_h_region4(tkind_sm1_t* const p_obj);

static sm_event_status_t tkind_sm1_dispatch_i_region5(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_j_region5(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_k_region5(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_l_region5(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_m_region5(tkind_sm1_t* const p_obj);

static sm_event_status_t tkind_sm1_dispatch_i_region6(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_k_region6(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_l_region6(tkind_sm1_t* const p_obj);

static sm_event_status_t tkind_sm1_dispatch_a_state1(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_b_state1(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_c_state1(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_d_state1(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_e_state1(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_f_state1(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_g_state1(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_h_state1(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_i_state1(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_j_state1(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_k_state1(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_l_state1(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_m_state1(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_n_state1(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_o_state1(tkind_sm1_t* const p_obj);

static sm_event_status_t tkind_sm1_dispatch_a_state2(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_b_state2(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_c_state3(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_d_state3(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_e_state3(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_f_state4(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_g_state4(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_h_state4(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_n_state3(tkind_sm1_t* const p_obj);

static sm_event_status_t tkind_sm1_dispatch_d_state5(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_e_state5(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_n_state5(tkind_sm1_t* const p_obj);

static sm_event_status_t tkind_sm1_dispatch_g_state6(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_h_state6(tkind_sm1_t* const p_obj);

static sm_event_status_t tkind_sm1_dispatch_i_state8(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_j_state7(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_k_state8(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_l_state8(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_m_state8(tkind_sm1_t* const p_obj);

static sm_event_status_t tkind_sm1_dispatch_i_state9(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_k_state9(tkind_sm1_t* const p_obj);
static sm_event_status_t tkind_sm1_dispatch_l_state9(tkind_sm1_t* const p_obj);

static sm_event_status_t tkind_sm1_enter_choice1(tkind_sm1_t* const p_obj);

/*******************************************************************************
 *
 * Static data declarations.
 *
 ******************************************************************************/
/**
 * @brief The initialized virtual table for the tkind_cbase1_s struct.
 */
static const tkind_cbase1_vt_t tkind_cbase1_vtable = 
{
    .p_setuintprop                   = tkind_cbase1_set_uint_default
};

/**
 * @brief The initialized virtual table for the tkind_cbase2_s struct.
 */
static const tkind_cbase2_vt_t tkind_cbase2_vtable = 
{
    .p_getfloatprop                  = tkind_cbase2_get_flt_dflt
};

/**
 * @brief The initialized virtual table for the tkind_ctest_s struct.
 */
static const tkind_ctest_vt_t tkind_ctest_vtable = 
{
    .cbase1.p_setuintprop            = tkind_ctest_set_uint_incr,
    .cbase2.p_getfloatprop           = tkind_ctest_get_flt_from_uint
};

/**
 * @brief An array with fifo queue sizes for each event type.
 */
static const fifo_size_t
tkind_ctest_fifo_sizes[TKIND_CTEST_EVENT_COUNT] =
{
    TKIND_CTEST_I_CNT,
    TKIND_CTEST_O_CNT,
    TKIND_CTEST_A_CNT,
    TKIND_CTEST_B_CNT,
    TKIND_CTEST_C_CNT,
    TKIND_CTEST_F_CNT,
    TKIND_CTEST_E_CNT,
    TKIND_CTEST_D_CNT,
    TKIND_CTEST_N_CNT,
    TKIND_CTEST_H_CNT,
    TKIND_CTEST_G_CNT,
    TKIND_CTEST_J_CNT,
    TKIND_CTEST_M_CNT,
    TKIND_CTEST_K_CNT,
    TKIND_CTEST_L_CNT
};
/*******************************************************************************
 *
 * Inline functions.
 *
 ******************************************************************************/
/**
 * @brief Obtains the pointer to the specialized ctest class from the pointer to
 * the cbase2 class.
 * @details This function is static inline, so that it is available practically
 * only to the virtual functions for casting tkind_cbase2_t to the specialized
 * types.
 * @param [in] p_cbase2 The pointer to the base class object.
 * @param [out] pp_ctest The pointer to the location where the seeked child
 * pointer should be stored.
 * @return true if the searched pointer was found and stored in the target
 * pointer.
 */
static inline bool
tkind_ctest_cast_from_cbase2(tkind_cbase2_t* const p_cbase2,\
                             tkind_ctest_t** const pp_ctest)
{
    bool b_is_copied = false;

    /* Check if this is really ctest class object 
       by checking the specialized virtual function table which was assigned by
       ctest class constructor.*/
    if((NULL != pp_ctest) && (NULL != p_cbase2)
            && (&tkind_ctest_vtable.cbase2 == p_cbase2->p_vtable))
    {
        *pp_ctest = (tkind_ctest_t*)(
                         (uintptr_t)p_cbase2 - offsetof(tkind_ctest_t, cbase2));
        b_is_copied = true;
    }

    return b_is_copied;
}

/**
 * @brief Enters the State1 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
tkind_sm1_enter_state1(tkind_sm1_t* const p_obj)
{
    p_obj->region1 = TKIND_SM1_STATE1;
    tkind_sm1_rec_log(p_obj, "Enter State1\n");
}

/**
 * @brief Enters the State3 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
tkind_sm1_enter_state3(tkind_sm1_t* const p_obj)
{
    p_obj->region2 = TKIND_SM1_STATE3;
    tkind_sm1_rec_log(p_obj, "Enter State3\n");
}

/**
 * @brief Enters the State5 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
tkind_sm1_enter_state5(tkind_sm1_t* const p_obj)
{
    p_obj->region3 = TKIND_SM1_STATE5;
    tkind_sm1_rec_log(p_obj, "Enter State5\n");
}

/**
 * @brief Enters the State2 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
tkind_sm1_enter_state2(tkind_sm1_t* const p_obj)
{
    p_obj->region2 = TKIND_SM1_STATE2;
    tkind_sm1_rec_log(p_obj, "Enter State2\n");
}

/**
 * @brief Enters the State4 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
tkind_sm1_enter_state4(tkind_sm1_t* const p_obj)
{
    p_obj->region2 = TKIND_SM1_STATE4;
    tkind_sm1_rec_log(p_obj, "Enter State4\n");
}

/**
 * @brief Enters the State6 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
tkind_sm1_enter_state6(tkind_sm1_t* const p_obj)
{
    p_obj->region4 = TKIND_SM1_STATE6;
    tkind_sm1_rec_log(p_obj, "Enter State6\n");
}

/**
 * @brief Enters the State7 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
tkind_sm1_enter_state7(tkind_sm1_t* const p_obj)
{
    p_obj->region5 = TKIND_SM1_STATE7;
    tkind_sm1_rec_log(p_obj, "Enter State7\n");
}

/**
 * @brief Enters the State8 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
tkind_sm1_enter_state8(tkind_sm1_t* const p_obj)
{
    p_obj->region5 = TKIND_SM1_STATE8;
    tkind_sm1_rec_log(p_obj, "Enter State8\n");
}

/**
 * @brief Enters the State9 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
tkind_sm1_enter_state9(tkind_sm1_t* const p_obj)
{
    p_obj->region6 = TKIND_SM1_STATE9;
    tkind_sm1_rec_log(p_obj, "Enter State9\n");
}

/**
 * @brief Implements entry of the Region3 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
tkind_sm1_enter_region3(tkind_sm1_t* const p_obj)
{
    p_obj->region3 = TKIND_SM1_REGION3_INL;
}

/**
 * @brief Implements entry of the Region4 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
tkind_sm1_enter_region4(tkind_sm1_t* const p_obj)
{
    p_obj->region4 = TKIND_SM1_REGION4_INL;
}

/**
 * @brief Implements entry of the Region2 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
tkind_sm1_enter_region2(tkind_sm1_t* const p_obj)
{
    p_obj->region2 = TKIND_SM1_INITIAL3;
    tkind_sm1_rec_log(p_obj, "Initial3 to State2\n");
    tkind_sm1_enter_state2(p_obj);
}

/**
 * @brief Implements entry of the Region6 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
tkind_sm1_enter_region6(tkind_sm1_t* const p_obj)
{
    p_obj->region6 = TKIND_SM1_INITIAL4;
    tkind_sm1_rec_log(p_obj, "Initial4 to State9\n");
    tkind_sm1_enter_state9(p_obj);
}

/**
 * @brief Implements entry of the Region5 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
tkind_sm1_enter_region5(tkind_sm1_t* const p_obj)
{
    p_obj->region5 = TKIND_SM1_REGION5_INL;
}

/**
 * @brief Implements entry of the Region1 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
tkind_sm1_enter_region1(tkind_sm1_t* const p_obj)
{
    p_obj->region1 = TKIND_SM1_INITIAL1;
    tkind_sm1_rec_log(p_obj, "Initial1 to State1\n");
    tkind_sm1_enter_state1(p_obj);
    tkind_sm1_enter_region2(p_obj);
    tkind_sm1_enter_region5(p_obj);
}

/**
 * @brief Exits the State1 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
tkind_sm1_exit_state1(tkind_sm1_t* const p_obj)
{
    tkind_sm1_exit_region2(p_obj);
    tkind_sm1_exit_region5(p_obj);
    tkind_sm1_rec_log(p_obj, "Exit State1\n");
}

/**
 * @brief Exits the State3 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
tkind_sm1_exit_state3(tkind_sm1_t* const p_obj)
{
    tkind_sm1_exit_region3(p_obj);
    tkind_sm1_rec_log(p_obj, "Exit State3\n");
}

/**
 * @brief Exits the State5 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
tkind_sm1_exit_state5(tkind_sm1_t* const p_obj)
{
    tkind_sm1_rec_log(p_obj, "Exit State5\n");
}

/**
 * @brief Exits the State2 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
tkind_sm1_exit_state2(tkind_sm1_t* const p_obj)
{
    tkind_sm1_rec_log(p_obj, "Exit State2\n");
}

/**
 * @brief Exits the State4 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
tkind_sm1_exit_state4(tkind_sm1_t* const p_obj)
{
    tkind_sm1_exit_region4(p_obj);
    tkind_sm1_rec_log(p_obj, "Exit State4\n");
}

/**
 * @brief Exits the State6 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
tkind_sm1_exit_state6(tkind_sm1_t* const p_obj)
{
    tkind_sm1_rec_log(p_obj, "Exit State6\n");
}

/**
 * @brief Exits the State7 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
tkind_sm1_exit_state7(tkind_sm1_t* const p_obj)
{
    tkind_sm1_rec_log(p_obj, "Exit State7\n");
}

/**
 * @brief Exits the State8 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
tkind_sm1_exit_state8(tkind_sm1_t* const p_obj)
{
    tkind_sm1_exit_region6(p_obj);
    tkind_sm1_rec_log(p_obj, "Exit State8\n");
}

/**
 * @brief Exits the State9 state of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static inline void
tkind_sm1_exit_state9(tkind_sm1_t* const p_obj)
{
    tkind_sm1_rec_log(p_obj, "Exit State9\n");
}

/*******************************************************************************
 *
 * Public function bodies.
 *
 ******************************************************************************/
/**
 * @brief The initialization function of the cbase1 class.
 * @param [in] p_obj The pointer to the self object.
 * @return 
 */
bool
tkind_cbase1_init(tkind_cbase1_t* const p_obj)
{
    bool b_is_created = false;

    if(NULL != p_obj)
    {
        tkind_cbase1_init_df(p_obj);
        b_is_created = true;
    }

    return b_is_created;
}

/**
 * @param [in] p_obj The pointer to the self object.
 * @param [in] param1 
 */
void
tkind_cbase1_setuintprop(tkind_cbase1_t* const p_obj, uint32_t const param1)
{
    /*Code for handling a virtual operation.*/
    if((NULL != p_obj) && (NULL != p_obj->p_vtable))
    {
        void (*p_setuintprop)(tkind_cbase1_t* const p_obj,\
                              uint32_t const param1)
            = p_obj->p_vtable->p_setuintprop;

        if(NULL != p_setuintprop)
        {
            p_setuintprop(p_obj, param1);
        }
    }
}

/**
 * @param [in] p_obj The pointer to the self object.
 * @return 
 */
uint32_t
tkind_cbase1_getuintprop(tkind_cbase1_t* const p_obj)
{
    return p_obj->Property1;
}

/**
 * @brief The initialization function of the cbase2 class.
 * @param [in] p_obj The pointer to the self object.
 * @return 
 */
bool
tkind_cbase2_init(tkind_cbase2_t* const p_obj)
{
    bool b_is_created = false;

    if(NULL != p_obj)
    {
        tkind_cbase2_init_df(p_obj);
        b_is_created = true;
    }

    return b_is_created;
}

/**
 * @param [in] p_obj The pointer to the self object.
 * @param [in] param1 
 */
void
tkind_cbase2_setfloatprop(tkind_cbase2_t* const p_obj, float const param1)
{
    p_obj->Property1 = param1;
}

/**
 * @param [in] p_obj The pointer to the self object.
 * @return 
 */
float
tkind_cbase2_getfloatprop(tkind_cbase2_t* const p_obj)
{
    float result = 0.0;
    /*Code for handling a virtual operation.*/
    if((NULL != p_obj) && (NULL != p_obj->p_vtable))
    {
        float (*p_getfloatprop)(tkind_cbase2_t* const p_obj)
            = p_obj->p_vtable->p_getfloatprop;

        if(NULL != p_getfloatprop)
        {
            result = p_getfloatprop(p_obj);
        }
    }

    return result;
}

/**
 * @brief The initialization function of the ctest class.
 * @param [in] p_obj The pointer to the self object.
 * @param [in,out] p_logger The pointer to the logger object.
 * @return 
 */
bool
tkind_ctest_init(tkind_ctest_t* const p_obj, plogger_logger_t* const p_logger)
{
    bool b_is_created = false;

    if((NULL != p_obj)
        && tkind_cbase1_init(&p_obj->cbase1)
        && tkind_cbase2_init(&p_obj->cbase2))
    {
        tkind_ctest_init_df(p_obj);
        b_is_created = true;
        /* First it is necessary to initialize fifo objects for each event
         * separately.*/
        b_is_created = b_is_created && fifo_initialize(
                        (&p_obj->event_pool.fifo_pool[TKIND_CTEST_I].fifo),
                        TKIND_CTEST_I_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TKIND_CTEST_I].p_next_events
                       = p_obj->event_pool.i_next_events;
        
        b_is_created = b_is_created && fifo_initialize(
                        (&p_obj->event_pool.fifo_pool[TKIND_CTEST_O].fifo),
                        TKIND_CTEST_O_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TKIND_CTEST_O].p_next_events
                       = p_obj->event_pool.o_next_events;
        
        b_is_created = b_is_created && fifo_initialize(
                        (&p_obj->event_pool.fifo_pool[TKIND_CTEST_A].fifo),
                        TKIND_CTEST_A_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TKIND_CTEST_A].p_next_events
                       = p_obj->event_pool.a_next_events;
        
        b_is_created = b_is_created && fifo_initialize(
                        (&p_obj->event_pool.fifo_pool[TKIND_CTEST_B].fifo),
                        TKIND_CTEST_B_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TKIND_CTEST_B].p_next_events
                       = p_obj->event_pool.b_next_events;
        
        b_is_created = b_is_created && fifo_initialize(
                        (&p_obj->event_pool.fifo_pool[TKIND_CTEST_C].fifo),
                        TKIND_CTEST_C_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TKIND_CTEST_C].p_next_events
                       = p_obj->event_pool.c_next_events;
        
        b_is_created = b_is_created && fifo_initialize(
                        (&p_obj->event_pool.fifo_pool[TKIND_CTEST_F].fifo),
                        TKIND_CTEST_F_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TKIND_CTEST_F].p_next_events
                       = p_obj->event_pool.f_next_events;
        
        b_is_created = b_is_created && fifo_initialize(
                        (&p_obj->event_pool.fifo_pool[TKIND_CTEST_E].fifo),
                        TKIND_CTEST_E_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TKIND_CTEST_E].p_next_events
                       = p_obj->event_pool.e_next_events;
        
        b_is_created = b_is_created && fifo_initialize(
                        (&p_obj->event_pool.fifo_pool[TKIND_CTEST_D].fifo),
                        TKIND_CTEST_D_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TKIND_CTEST_D].p_next_events
                       = p_obj->event_pool.d_next_events;
        
        b_is_created = b_is_created && fifo_initialize(
                        (&p_obj->event_pool.fifo_pool[TKIND_CTEST_N].fifo),
                        TKIND_CTEST_N_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TKIND_CTEST_N].p_next_events
                       = p_obj->event_pool.n_next_events;
        
        b_is_created = b_is_created && fifo_initialize(
                        (&p_obj->event_pool.fifo_pool[TKIND_CTEST_H].fifo),
                        TKIND_CTEST_H_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TKIND_CTEST_H].p_next_events
                       = p_obj->event_pool.h_next_events;
        
        b_is_created = b_is_created && fifo_initialize(
                        (&p_obj->event_pool.fifo_pool[TKIND_CTEST_G].fifo),
                        TKIND_CTEST_G_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TKIND_CTEST_G].p_next_events
                       = p_obj->event_pool.g_next_events;
        
        b_is_created = b_is_created && fifo_initialize(
                        (&p_obj->event_pool.fifo_pool[TKIND_CTEST_J].fifo),
                        TKIND_CTEST_J_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TKIND_CTEST_J].p_next_events
                       = p_obj->event_pool.j_next_events;
        
        b_is_created = b_is_created && fifo_initialize(
                        (&p_obj->event_pool.fifo_pool[TKIND_CTEST_M].fifo),
                        TKIND_CTEST_M_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TKIND_CTEST_M].p_next_events
                       = p_obj->event_pool.m_next_events;
        
        b_is_created = b_is_created && fifo_initialize(
                        (&p_obj->event_pool.fifo_pool[TKIND_CTEST_K].fifo),
                        TKIND_CTEST_K_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TKIND_CTEST_K].p_next_events
                       = p_obj->event_pool.k_next_events;
        
        b_is_created = b_is_created && fifo_initialize(
                        (&p_obj->event_pool.fifo_pool[TKIND_CTEST_L].fifo),
                        TKIND_CTEST_L_CNT, 0u, 0u);
        p_obj->event_pool.fifo_pool[TKIND_CTEST_L].p_next_events
                       = p_obj->event_pool.l_next_events;
        
        p_obj->event_pool.event_proc_status = SM_EVENT_STATUS_DISPATCHED;
        p_obj->event_pool.fetched_event =
                                    (event_pool_locator_t)
                                    {.event_type = TKIND_CTEST_EVENT_COUNT,
                                     .event_index = (~((fifo_size_t) 0u))};
        
        /* Then the initialized fifo_pool can be used to initialize the
         * event_pool manager.*/
        b_is_created = b_is_created
                        && event_pool_initialize(&p_obj->event_pool.manager,\
                                                 p_obj->event_pool.fifo_pool,\
                                                 tkind_ctest_fifo_sizes,\
                                                 TKIND_CTEST_EVENT_COUNT);
        
        p_obj->p_logger = p_logger;
        /* Initialize the state machine. */
        tkind_ctest_start_sm1(p_obj);
    }

    return b_is_created;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
tkind_ctest_a(tkind_ctest_t* const p_obj)
{
    bool b_is_added = false;
    
    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TKIND_CTEST_A);
    }
    
    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
tkind_ctest_b(tkind_ctest_t* const p_obj)
{
    bool b_is_added = false;
    
    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TKIND_CTEST_B);
    }
    
    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
tkind_ctest_c(tkind_ctest_t* const p_obj)
{
    bool b_is_added = false;
    
    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TKIND_CTEST_C);
    }
    
    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
tkind_ctest_d(tkind_ctest_t* const p_obj)
{
    bool b_is_added = false;
    
    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TKIND_CTEST_D);
    }
    
    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
tkind_ctest_e(tkind_ctest_t* const p_obj)
{
    bool b_is_added = false;
    
    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TKIND_CTEST_E);
    }
    
    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
tkind_ctest_f(tkind_ctest_t* const p_obj)
{
    bool b_is_added = false;
    
    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TKIND_CTEST_F);
    }
    
    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
tkind_ctest_g(tkind_ctest_t* const p_obj)
{
    bool b_is_added = false;
    
    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TKIND_CTEST_G);
    }
    
    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
tkind_ctest_h(tkind_ctest_t* const p_obj)
{
    bool b_is_added = false;
    
    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TKIND_CTEST_H);
    }
    
    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
tkind_ctest_i(tkind_ctest_t* const p_obj)
{
    bool b_is_added = false;
    
    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TKIND_CTEST_I);
    }
    
    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
tkind_ctest_j(tkind_ctest_t* const p_obj)
{
    bool b_is_added = false;
    
    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TKIND_CTEST_J);
    }
    
    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
tkind_ctest_k(tkind_ctest_t* const p_obj)
{
    bool b_is_added = false;
    
    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TKIND_CTEST_K);
    }
    
    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
tkind_ctest_l(tkind_ctest_t* const p_obj)
{
    bool b_is_added = false;
    
    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TKIND_CTEST_L);
    }
    
    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
tkind_ctest_m(tkind_ctest_t* const p_obj)
{
    bool b_is_added = false;
    
    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TKIND_CTEST_M);
    }
    
    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
tkind_ctest_n(tkind_ctest_t* const p_obj)
{
    bool b_is_added = false;
    
    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TKIND_CTEST_N);
    }
    
    return b_is_added;
}

/**
 * @param [in] p_obj The pointer to the self object.
 */
bool
tkind_ctest_o(tkind_ctest_t* const p_obj)
{
    bool b_is_added = false;
    
    if(NULL != p_obj)
    {
        b_is_added = event_pool_enqueue(&p_obj->event_pool.manager,
                                        (event_pool_size_t) TKIND_CTEST_O);
    }
    
    return b_is_added;
}

/**
 * @brief Fetches the first event pending in the event pool.
 * @details This function is separated to allow the user to call it from an
 * enclosing critical section when needed.
 * @param [in] p_obj The pointer to the self object.
 * @returns true, when an event was fetched from the event pool and is waiting
 * for processing.
 * @returns false, when the event pool is empty, or the p_obj is NULL.
 */
bool
tkind_ctest_fetch_event(tkind_ctest_t* const p_obj)
{
    bool b_is_new_event = false;

    if(NULL != p_obj)
    {
        switch(p_obj->event_pool.event_proc_status)
        {
            case SM_EVENT_STATUS_DISPATCHED:
                p_obj->event_pool.fetched_event =
                    (event_pool_locator_t)
                    {.event_type = TKIND_CTEST_EVENT_COUNT,
                     .event_index = (~((fifo_size_t) 0u))};
                b_is_new_event =
                    event_pool_get_first_head(&p_obj->event_pool.manager,\
                                              &p_obj->event_pool.fetched_event);
                break;
            case SM_EVENT_STATUS_PENDING:
                b_is_new_event = true;
                break;
            default:
                break;
        }

        if(b_is_new_event)
        {
            p_obj->event_pool.event_proc_status = SM_EVENT_STATUS_PENDING;
        }
    }

    return b_is_new_event;
}

/**
 * @brief Executes the proper action corresponding to the event fetched from the
 * event pool.
 * @details This function was separated from the other two (*fetch* and
 * *release*) functions, because in normal scenario this function doesn't need
 * to be called from a critical section. Since the event at the head of the
 * event pool has already been fetched, no action on the event pool is able to
 * modify the event data contents. Because the event data is still in the event
 * pool, there is no need for an additional temporary buffer for keeping a copy
 * of the event data (which could be troublesome due to separate data types for
 * each event).
 * To access the required event data it is enough to use information in the
 * 'event_pool.fetched_event' field. This approach saves memory and has no need
 * of event data copying, but may be only a little slower when accessing the
 * event data due to retrieving information from the 'event_pool.fetched_event'
 * field.
 * @returns true when a fetched event was waiting for processing.
 * @returns false when there was no event waiting for processing or the p_obj
 * was NULL.
 */
bool
tkind_ctest_dispatch_event(tkind_ctest_t* const p_obj)
{
    bool b_is_new_event = false;

    if ((NULL != p_obj)
        && (SM_EVENT_STATUS_PENDING == p_obj->event_pool.event_proc_status))
    {
        sm_event_status_t temp_status = SM_EVENT_STATUS_IGNORED;

        switch(p_obj->event_pool.fetched_event.event_type)
        {
            case TKIND_CTEST_I:
                temp_status = tkind_sm1_dispatch_i(&p_obj->sm1);
                break;
            case TKIND_CTEST_O:
                temp_status = tkind_sm1_dispatch_o(&p_obj->sm1);
                break;
            case TKIND_CTEST_A:
                temp_status = tkind_sm1_dispatch_a(&p_obj->sm1);
                break;
            case TKIND_CTEST_B:
                temp_status = tkind_sm1_dispatch_b(&p_obj->sm1);
                break;
            case TKIND_CTEST_C:
                temp_status = tkind_sm1_dispatch_c(&p_obj->sm1);
                break;
            case TKIND_CTEST_F:
                temp_status = tkind_sm1_dispatch_f(&p_obj->sm1);
                break;
            case TKIND_CTEST_E:
                temp_status = tkind_sm1_dispatch_e(&p_obj->sm1);
                break;
            case TKIND_CTEST_D:
                temp_status = tkind_sm1_dispatch_d(&p_obj->sm1);
                break;
            case TKIND_CTEST_N:
                temp_status = tkind_sm1_dispatch_n(&p_obj->sm1);
                break;
            case TKIND_CTEST_H:
                temp_status = tkind_sm1_dispatch_h(&p_obj->sm1);
                break;
            case TKIND_CTEST_G:
                temp_status = tkind_sm1_dispatch_g(&p_obj->sm1);
                break;
            case TKIND_CTEST_J:
                temp_status = tkind_sm1_dispatch_j(&p_obj->sm1);
                break;
            case TKIND_CTEST_M:
                temp_status = tkind_sm1_dispatch_m(&p_obj->sm1);
                break;
            case TKIND_CTEST_K:
                temp_status = tkind_sm1_dispatch_k(&p_obj->sm1);
                break;
            case TKIND_CTEST_L:
                temp_status = tkind_sm1_dispatch_l(&p_obj->sm1);
                break;
            default:
                break;
        }

        p_obj->event_pool.event_proc_status = temp_status;
        b_is_new_event = true;
    }

    return b_is_new_event;
}

/**
 * @brief Removes the processed event from the event pool.
 * @details This function is separated to allow the user to call it from an
 * enclosing critical section when needed.
 * @param [in] p_obj The pointer to the self object of the ctest class.
 * @returns true, if the last fetched event had already been processed and then
 * removed from the event pool.
 * @returns false if the p_obj is NULL or there was no processed event in the
 * event pool.
 */
bool
tkind_ctest_release_event(tkind_ctest_t* const p_obj)
{
    bool b_is_released = false;

    if ((NULL != p_obj)
        && (SM_EVENT_STATUS_PENDING < p_obj->event_pool.event_proc_status)
        && (SM_EVENT_STATUS_DISPATCHED > p_obj->event_pool.event_proc_status))
    {
        b_is_released = event_pool_dequeue(&p_obj->event_pool.manager);

        if(b_is_released)
        {
            p_obj->event_pool.event_proc_status = SM_EVENT_STATUS_DISPATCHED;
        }
    }

    return b_is_released;
}

/*******************************************************************************
 *
 * Non-public function bodies.
 *
 ******************************************************************************/
/**
 * @brief The initializer function of the default values and virtual tables of
 * the tkind_cbase1_s struct. Generated automatically for properties for which a
 * default value was specified in the UML model.
 * @param [in] p_obj The pointer to the self object.
 */
static void
tkind_cbase1_init_df(tkind_cbase1_t* const p_obj)
{
    p_obj->p_vtable                  = &tkind_cbase1_vtable;
}

/**
 * @param [in] p_obj The pointer to the self object.
 * @param [in] param1 
 */
void
tkind_cbase1_set_uint_default(tkind_cbase1_t* const p_obj,\
                              uint32_t const param1)
{
    p_obj->Property1 = param1;
}

/**
 * @brief The initializer function of the default values and virtual tables of
 * the tkind_cbase2_s struct. Generated automatically for properties for which a
 * default value was specified in the UML model.
 * @param [in] p_obj The pointer to the self object.
 */
static void
tkind_cbase2_init_df(tkind_cbase2_t* const p_obj)
{
    p_obj->p_vtable                  = &tkind_cbase2_vtable;
}

/**
 * @param [in] p_obj The pointer to the self object.
 * @return 
 */
static float
tkind_cbase2_get_flt_dflt(tkind_cbase2_t* const p_obj)
{
    return p_obj->Property1;
}

/**
 * @brief The initializer function of the default values and virtual tables of
 * the tkind_ctest_s struct. Generated automatically for properties for which a
 * default value was specified in the UML model.
 * @param [in] p_obj The pointer to the self object.
 */
static void
tkind_ctest_init_df(tkind_ctest_t* const p_obj)
{
    p_obj->pi                        = TKIND_PI_LITERAL_CONSTANT;
    p_obj->cbase1.p_vtable           = &tkind_ctest_vtable.cbase1;
    p_obj->cbase2.p_vtable           = &tkind_ctest_vtable.cbase2;
}

/**
 * @brief Initializes the sm1 state machine.
 * @details According to UML, the state machine must be invoked first, which
 * will lead to its initialization and execution of the initial transition.
 * @param [in] p_obj The pointer to the self object.
 */
static void
tkind_ctest_start_sm1(tkind_ctest_t* const p_obj)
{
    p_obj->sm1.p_context             = p_obj;
    p_obj->sm1.region1               = TKIND_SM1_INITIAL1;
    p_obj->sm1.region2               = TKIND_SM1_INITIAL3;
    p_obj->sm1.region3               = TKIND_SM1_REGION3_INL;
    p_obj->sm1.region4               = TKIND_SM1_REGION4_INL;
    p_obj->sm1.region5               = TKIND_SM1_REGION5_INL;
    p_obj->sm1.region6               = TKIND_SM1_INITIAL4;
    
    tkind_sm1_init_df(&p_obj->sm1);
    /* Execute the initial transition.*/
    tkind_sm1_enter_region1(&p_obj->sm1);
}

/**
 * @param [in] p_obj The pointer to the self object.
 * @param [in] param1 
 */
void
tkind_ctest_set_uint_incr(tkind_cbase1_t* const p_obj, uint32_t const param1)
{
    p_obj->Property1 = param1 + 1u;
}

/**
 * @brief Implementation of virtual function GetFloatProp () from the cbase2
 * class.
 * @details It shows how a pointer to a base class can be converted to a pointer
 * to a child class.
 * After the pointer conversion, it returns the Property1 value of the another
 * base class (cbase1).
 * @param [in] p_obj The pointer to the self object.
 * @return 
 */
static float
tkind_ctest_get_flt_from_uint(tkind_cbase2_t* const p_obj)
{
    float result = 0.0f;
    tkind_ctest_t* p_ctest = NULL;
    
    if(tkind_ctest_cast_from_cbase2(p_obj, &p_ctest))
    {
        /*Here the p_ctest pointer has the correct value.*/
        /*Intentionally get the value of Property1 from the other base class
          (cbase1).*/
        result = (float)p_ctest->cbase1.Property1;
    }
    
    return result;
}

/**
 * @brief The initializer function of the default values and virtual tables of
 * the tkind_sm1_s struct. Generated automatically for properties for which a
 * default value was specified in the UML model.
 * @param [in] p_obj The pointer to the self object.
 */
static void
tkind_sm1_init_df(tkind_sm1_t* const p_obj)
{
    p_obj->b_test_condition          = false;
}

/**
 * @param [in] p_obj The pointer to the self object.
 * @param [in] p_str 
 */
static void
tkind_sm1_rec_log(tkind_sm1_t* const p_obj, const char* const p_str)
{
    plogger_logger_record(p_obj->p_context->p_logger, p_str);
}

/**
 * @brief Exits the Region2 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static void
tkind_sm1_exit_region2(tkind_sm1_t* const p_obj)
{
    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE3:
            tkind_sm1_exit_state3(p_obj);
            break;
        case TKIND_SM1_STATE2:
            tkind_sm1_exit_state2(p_obj);
            break;
        case TKIND_SM1_STATE4:
            tkind_sm1_exit_state4(p_obj);
            break;
        default:
            break;
    }

    // Mark the region is already exited.
    p_obj->region2 = TKIND_SM1_INITIAL3;
}

/**
 * @brief Exits the Region3 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static void
tkind_sm1_exit_region3(tkind_sm1_t* const p_obj)
{
    switch(p_obj->region3)
    {
        case TKIND_SM1_STATE5:
            tkind_sm1_exit_state5(p_obj);
            break;
        default:
            break;
    }

    // Mark the region is already exited.
    p_obj->region3 = TKIND_SM1_REGION3_INL;
}

/**
 * @brief Exits the Region4 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static void
tkind_sm1_exit_region4(tkind_sm1_t* const p_obj)
{
    switch(p_obj->region4)
    {
        case TKIND_SM1_STATE6:
            tkind_sm1_exit_state6(p_obj);
            break;
        default:
            break;
    }

    // Mark the region is already exited.
    p_obj->region4 = TKIND_SM1_REGION4_INL;
}

/**
 * @brief Exits the Region5 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static void
tkind_sm1_exit_region5(tkind_sm1_t* const p_obj)
{
    switch(p_obj->region5)
    {
        case TKIND_SM1_STATE7:
            tkind_sm1_exit_state7(p_obj);
            break;
        case TKIND_SM1_STATE8:
            tkind_sm1_exit_state8(p_obj);
            break;
        default:
            break;
    }

    // Mark the region is already exited.
    p_obj->region5 = TKIND_SM1_REGION5_INL;
}

/**
 * @brief Exits the Region6 region of the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 */
static void
tkind_sm1_exit_region6(tkind_sm1_t* const p_obj)
{
    switch(p_obj->region6)
    {
        case TKIND_SM1_STATE9:
            tkind_sm1_exit_state9(p_obj);
            break;
        default:
            break;
    }

    // Mark the region is already exited.
    p_obj->region6 = TKIND_SM1_INITIAL4;
}

/**
 * @brief Implements a event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_a(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = tkind_sm1_dispatch_a_state1(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements b event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_b(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = tkind_sm1_dispatch_b_state1(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements c event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_c(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = tkind_sm1_dispatch_c_state1(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements d event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_d(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = tkind_sm1_dispatch_d_state1(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements e event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_e(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = tkind_sm1_dispatch_e_state1(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements f event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_f(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = tkind_sm1_dispatch_f_state1(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements g event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_g(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = tkind_sm1_dispatch_g_state1(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements h event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_h(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = tkind_sm1_dispatch_h_state1(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements i event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_i(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = tkind_sm1_dispatch_i_state1(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements j event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_j(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = tkind_sm1_dispatch_j_state1(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements k event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_k(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = tkind_sm1_dispatch_k_state1(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements l event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_l(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = tkind_sm1_dispatch_l_state1(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements m event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_m(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = tkind_sm1_dispatch_m_state1(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements n event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_n(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = tkind_sm1_dispatch_n_state1(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements o event handling by the sm1 state machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_o(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region1)
    {
        case TKIND_SM1_STATE1:
            result = tkind_sm1_dispatch_o_state1(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements a event handling by the Region2 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_a_region2(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE2:
            result = tkind_sm1_dispatch_a_state2(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements b event handling by the Region2 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_b_region2(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE2:
            result = tkind_sm1_dispatch_b_state2(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements c event handling by the Region2 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_c_region2(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE3:
            result = tkind_sm1_dispatch_c_state3(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements d event handling by the Region2 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_d_region2(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE3:
            result = tkind_sm1_dispatch_d_state3(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements e event handling by the Region2 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_e_region2(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE3:
            result = tkind_sm1_dispatch_e_state3(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements f event handling by the Region2 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_f_region2(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE4:
            result = tkind_sm1_dispatch_f_state4(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements g event handling by the Region2 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_g_region2(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE4:
            result = tkind_sm1_dispatch_g_state4(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements h event handling by the Region2 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_h_region2(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE4:
            result = tkind_sm1_dispatch_h_state4(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements n event handling by the Region2 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_n_region2(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region2)
    {
        case TKIND_SM1_STATE3:
            result = tkind_sm1_dispatch_n_state3(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements d event handling by the Region3 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_d_region3(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region3)
    {
        case TKIND_SM1_STATE5:
            result = tkind_sm1_dispatch_d_state5(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements e event handling by the Region3 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_e_region3(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region3)
    {
        case TKIND_SM1_STATE5:
            result = tkind_sm1_dispatch_e_state5(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements n event handling by the Region3 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_n_region3(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region3)
    {
        case TKIND_SM1_STATE5:
            result = tkind_sm1_dispatch_n_state5(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements g event handling by the Region4 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_g_region4(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region4)
    {
        case TKIND_SM1_STATE6:
            result = tkind_sm1_dispatch_g_state6(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements h event handling by the Region4 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_h_region4(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region4)
    {
        case TKIND_SM1_STATE6:
            result = tkind_sm1_dispatch_h_state6(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements i event handling by the Region5 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_i_region5(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region5)
    {
        case TKIND_SM1_STATE8:
            result = tkind_sm1_dispatch_i_state8(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements j event handling by the Region5 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_j_region5(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region5)
    {
        case TKIND_SM1_STATE7:
            result = tkind_sm1_dispatch_j_state7(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements k event handling by the Region5 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_k_region5(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region5)
    {
        case TKIND_SM1_STATE8:
            result = tkind_sm1_dispatch_k_state8(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements l event handling by the Region5 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_l_region5(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region5)
    {
        case TKIND_SM1_STATE8:
            result = tkind_sm1_dispatch_l_state8(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements m event handling by the Region5 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_m_region5(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region5)
    {
        case TKIND_SM1_STATE8:
            result = tkind_sm1_dispatch_m_state8(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements i event handling by the Region6 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_i_region6(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region6)
    {
        case TKIND_SM1_STATE9:
            result = tkind_sm1_dispatch_i_state9(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements k event handling by the Region6 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_k_region6(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region6)
    {
        case TKIND_SM1_STATE9:
            result = tkind_sm1_dispatch_k_state9(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements l event handling by the Region6 region of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_l_region6(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    switch(p_obj->region6)
    {
        case TKIND_SM1_STATE9:
            result = tkind_sm1_dispatch_l_state9(p_obj);
            break;
        default:
            break;
    }

    return result;
}

/**
 * @brief Implements a event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_a_state1(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = tkind_sm1_dispatch_a_region2(p_obj);

    return result;
}

/**
 * @brief Implements b event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_b_state1(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = tkind_sm1_dispatch_b_region2(p_obj);

    return result;
}

/**
 * @brief Implements c event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_c_state1(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = tkind_sm1_dispatch_c_region2(p_obj);

    return result;
}

/**
 * @brief Implements d event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_d_state1(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = tkind_sm1_dispatch_d_region2(p_obj);

    return result;
}

/**
 * @brief Implements e event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_e_state1(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = tkind_sm1_dispatch_e_region2(p_obj);

    return result;
}

/**
 * @brief Implements f event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_f_state1(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = tkind_sm1_dispatch_f_region2(p_obj);

    return result;
}

/**
 * @brief Implements g event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_g_state1(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = tkind_sm1_dispatch_g_region2(p_obj);

    return result;
}

/**
 * @brief Implements h event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_h_state1(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = tkind_sm1_dispatch_h_region2(p_obj);

    return result;
}

/**
 * @brief Implements i event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_i_state1(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = tkind_sm1_dispatch_i_region5(p_obj);

    if(SM_EVENT_STATUS_IGNORED == result)
    {
        tkind_sm1_exit_state1(p_obj);
        tkind_sm1_rec_log(p_obj, "State1 to State7\n");
        tkind_sm1_enter_state1(p_obj);
        tkind_sm1_enter_state7(p_obj);
        tkind_sm1_enter_region2(p_obj);
    }

    return result;
}

/**
 * @brief Implements j event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_j_state1(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = tkind_sm1_dispatch_j_region5(p_obj);

    return result;
}

/**
 * @brief Implements k event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_k_state1(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = tkind_sm1_dispatch_k_region5(p_obj);

    return result;
}

/**
 * @brief Implements l event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_l_state1(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = tkind_sm1_dispatch_l_region5(p_obj);

    return result;
}

/**
 * @brief Implements m event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_m_state1(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = tkind_sm1_dispatch_m_region5(p_obj);

    return result;
}

/**
 * @brief Implements n event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_n_state1(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = tkind_sm1_dispatch_n_region2(p_obj);

    return result;
}

/**
 * @brief Implements o event handling by the State1 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_o_state1(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    tkind_sm1_exit_state1(p_obj);
    tkind_sm1_rec_log(p_obj, "State1 to Choice1\n");
    tkind_sm1_enter_state1(p_obj);
    tkind_sm1_enter_choice1(p_obj);
    tkind_sm1_enter_region2(p_obj);

    return result;
}

/**
 * @brief Implements a event handling by the State2 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_a_state2(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    tkind_sm1_exit_state2(p_obj);
    tkind_sm1_rec_log(p_obj, "State2 to State3\n");
    tkind_sm1_enter_state3(p_obj);
    tkind_sm1_enter_region3(p_obj);

    return result;
}

/**
 * @brief Implements b event handling by the State2 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_b_state2(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    tkind_sm1_exit_state2(p_obj);
    tkind_sm1_rec_log(p_obj, "State2 to State4\n");
    tkind_sm1_enter_state4(p_obj);
    tkind_sm1_enter_region4(p_obj);

    return result;
}

/**
 * @brief Implements c event handling by the State3 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_c_state3(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    tkind_sm1_exit_region3(p_obj);
    tkind_sm1_rec_log(p_obj, "State3 to State5\n");
    tkind_sm1_enter_state5(p_obj);

    return result;
}

/**
 * @brief Implements d event handling by the State3 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_d_state3(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = tkind_sm1_dispatch_d_region3(p_obj);

    return result;
}

/**
 * @brief Implements e event handling by the State3 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_e_state3(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = tkind_sm1_dispatch_e_region3(p_obj);

    return result;
}

/**
 * @brief Implements f event handling by the State4 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_f_state4(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    tkind_sm1_exit_state4(p_obj);
    tkind_sm1_rec_log(p_obj, "State4 to State6\n");
    tkind_sm1_enter_state4(p_obj);
    tkind_sm1_enter_state6(p_obj);

    return result;
}

/**
 * @brief Implements g event handling by the State4 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_g_state4(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = tkind_sm1_dispatch_g_region4(p_obj);

    return result;
}

/**
 * @brief Implements h event handling by the State4 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_h_state4(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = tkind_sm1_dispatch_h_region4(p_obj);

    return result;
}

/**
 * @brief Implements n event handling by the State3 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_n_state3(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = tkind_sm1_dispatch_n_region3(p_obj);

    return result;
}

/**
 * @brief Implements d event handling by the State5 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_d_state5(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    tkind_sm1_exit_region3(p_obj);
    tkind_sm1_rec_log(p_obj, "State5 to State3\n");
    tkind_sm1_enter_region3(p_obj);

    return result;
}

/**
 * @brief Implements e event handling by the State5 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_e_state5(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    tkind_sm1_exit_region2(p_obj);
    tkind_sm1_rec_log(p_obj, "State5 to State1\n");
    tkind_sm1_enter_region2(p_obj);

    return result;
}

/**
 * @brief Implements n event handling by the State5 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_n_state5(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    tkind_sm1_exit_state3(p_obj);
    tkind_sm1_rec_log(p_obj, "State5 to State6\n");
    tkind_sm1_enter_state4(p_obj);
    tkind_sm1_enter_state6(p_obj);

    return result;
}

/**
 * @brief Implements g event handling by the State6 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_g_state6(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    tkind_sm1_exit_state4(p_obj);
    tkind_sm1_rec_log(p_obj, "State6 to State4\n");
    tkind_sm1_enter_state4(p_obj);
    tkind_sm1_enter_region4(p_obj);

    return result;
}

/**
 * @brief Implements h event handling by the State6 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_h_state6(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    tkind_sm1_exit_state1(p_obj);
    tkind_sm1_rec_log(p_obj, "State6 to State1\n");
    tkind_sm1_enter_state1(p_obj);
    tkind_sm1_enter_region2(p_obj);
    tkind_sm1_enter_region5(p_obj);

    return result;
}

/**
 * @brief Implements i event handling by the State8 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_i_state8(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = tkind_sm1_dispatch_i_region6(p_obj);

    return result;
}

/**
 * @brief Implements j event handling by the State7 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_j_state7(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    tkind_sm1_exit_state7(p_obj);
    tkind_sm1_rec_log(p_obj, "State7 to State8\n");
    tkind_sm1_enter_state8(p_obj);
    tkind_sm1_enter_region6(p_obj);

    return result;
}

/**
 * @brief Implements k event handling by the State8 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_k_state8(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = tkind_sm1_dispatch_k_region6(p_obj);

    return result;
}

/**
 * @brief Implements l event handling by the State8 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_l_state8(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_IGNORED;

    result = tkind_sm1_dispatch_l_region6(p_obj);

    return result;
}

/**
 * @brief Implements m event handling by the State8 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_m_state8(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    tkind_sm1_exit_state1(p_obj);
    tkind_sm1_rec_log(p_obj, "State8 to State1\n");
    tkind_sm1_enter_state1(p_obj);
    tkind_sm1_enter_region2(p_obj);
    tkind_sm1_enter_region5(p_obj);

    return result;
}

/**
 * @brief Implements i event handling by the State9 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_i_state9(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    tkind_sm1_rec_log(p_obj, "Internal transition in State9 on event i\n");
    result = SM_EVENT_STATUS_SAMESTATE;

    return result;
}

/**
 * @brief Implements k event handling by the State9 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_k_state9(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    tkind_sm1_exit_state8(p_obj);
    tkind_sm1_rec_log(p_obj, "State9 to State8\n");
    tkind_sm1_enter_state8(p_obj);
    tkind_sm1_enter_region6(p_obj);

    return result;
}

/**
 * @brief Implements l event handling by the State9 state of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_dispatch_l_state9(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    tkind_sm1_exit_state1(p_obj);
    tkind_sm1_rec_log(p_obj, "State9 to State1\n");
    tkind_sm1_enter_state1(p_obj);
    tkind_sm1_enter_region2(p_obj);
    tkind_sm1_enter_region5(p_obj);

    return result;
}

/**
 * @brief Implements entry of the Choice1 choice Pseudostate of the sm1 state
 * machine.
 * @param [in] p_obj The pointer to the self object.
 * @return the event dispatch status.
 */
static sm_event_status_t
tkind_sm1_enter_choice1(tkind_sm1_t* const p_obj)
{
    sm_event_status_t result = SM_EVENT_STATUS_CHANGEDSTATE;

    if(p_obj->b_test_condition)
    {
        tkind_sm1_rec_log(p_obj, "Choice1 to State8\n");
        tkind_sm1_enter_state8(p_obj);
        tkind_sm1_enter_region6(p_obj);
    }
    else
    {
        tkind_sm1_rec_log(p_obj, "Choice1 to State1\n");
        tkind_sm1_enter_region5(p_obj);
    }
    
    return result;
}

/*** end of file ***/
