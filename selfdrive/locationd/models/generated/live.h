#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_5143167480548607913);
void live_err_fun(double *nom_x, double *delta_x, double *out_9005032120711497201);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_8493908803690439220);
void live_H_mod_fun(double *state, double *out_7839935593793205071);
void live_f_fun(double *state, double dt, double *out_6424921067404530909);
void live_F_fun(double *state, double dt, double *out_1343952971291642426);
void live_h_4(double *state, double *unused, double *out_661857367273697039);
void live_H_4(double *state, double *unused, double *out_6939367565542263736);
void live_h_9(double *state, double *unused, double *out_5368229095455893654);
void live_H_9(double *state, double *unused, double *out_6698177918912673091);
void live_h_10(double *state, double *unused, double *out_9093880920230483697);
void live_H_10(double *state, double *unused, double *out_5354209728630779718);
void live_h_12(double *state, double *unused, double *out_5525709263086545860);
void live_H_12(double *state, double *unused, double *out_1919911157510301941);
void live_h_35(double *state, double *unused, double *out_5541559177326160608);
void live_H_35(double *state, double *unused, double *out_825651874814711768);
void live_h_32(double *state, double *unused, double *out_3000175105784365080);
void live_H_32(double *state, double *unused, double *out_7791404745841565430);
void live_h_13(double *state, double *unused, double *out_1107653070166369951);
void live_H_13(double *state, double *unused, double *out_8100999459308818961);
void live_h_14(double *state, double *unused, double *out_5368229095455893654);
void live_H_14(double *state, double *unused, double *out_6698177918912673091);
void live_h_33(double *state, double *unused, double *out_7888272571291157081);
void live_H_33(double *state, double *unused, double *out_422148503530798756);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}