#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_6486958562498374070);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4487160442454099930);
void car_H_mod_fun(double *state, double *out_6726501929981504960);
void car_f_fun(double *state, double dt, double *out_4014964142285131911);
void car_F_fun(double *state, double dt, double *out_2355657713517530665);
void car_h_25(double *state, double *unused, double *out_6466845240886339756);
void car_H_25(double *state, double *unused, double *out_227966644233802315);
void car_h_24(double *state, double *unused, double *out_8082310701426017685);
void car_H_24(double *state, double *unused, double *out_756099226607511353);
void car_h_30(double *state, double *unused, double *out_8342449304569189510);
void car_H_30(double *state, double *unused, double *out_357305591377042385);
void car_h_26(double *state, double *unused, double *out_5102621501479516461);
void car_H_26(double *state, double *unused, double *out_3969469963107858539);
void car_h_27(double *state, double *unused, double *out_2515123931120501009);
void car_H_27(double *state, double *unused, double *out_2532068903177467296);
void car_h_29(double *state, double *unused, double *out_9160784916238699671);
void car_H_29(double *state, double *unused, double *out_4245431630047018329);
void car_h_28(double *state, double *unused, double *out_2486549336540344636);
void car_H_28(double *state, double *unused, double *out_9118913426593002713);
void car_h_31(double *state, double *unused, double *out_6066165806152463487);
void car_H_31(double *state, double *unused, double *out_197320682356841887);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}