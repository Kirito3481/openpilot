#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                       Code generated with SymPy 1.12                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_6486958562498374070) {
   out_6486958562498374070[0] = delta_x[0] + nom_x[0];
   out_6486958562498374070[1] = delta_x[1] + nom_x[1];
   out_6486958562498374070[2] = delta_x[2] + nom_x[2];
   out_6486958562498374070[3] = delta_x[3] + nom_x[3];
   out_6486958562498374070[4] = delta_x[4] + nom_x[4];
   out_6486958562498374070[5] = delta_x[5] + nom_x[5];
   out_6486958562498374070[6] = delta_x[6] + nom_x[6];
   out_6486958562498374070[7] = delta_x[7] + nom_x[7];
   out_6486958562498374070[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_4487160442454099930) {
   out_4487160442454099930[0] = -nom_x[0] + true_x[0];
   out_4487160442454099930[1] = -nom_x[1] + true_x[1];
   out_4487160442454099930[2] = -nom_x[2] + true_x[2];
   out_4487160442454099930[3] = -nom_x[3] + true_x[3];
   out_4487160442454099930[4] = -nom_x[4] + true_x[4];
   out_4487160442454099930[5] = -nom_x[5] + true_x[5];
   out_4487160442454099930[6] = -nom_x[6] + true_x[6];
   out_4487160442454099930[7] = -nom_x[7] + true_x[7];
   out_4487160442454099930[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_6726501929981504960) {
   out_6726501929981504960[0] = 1.0;
   out_6726501929981504960[1] = 0;
   out_6726501929981504960[2] = 0;
   out_6726501929981504960[3] = 0;
   out_6726501929981504960[4] = 0;
   out_6726501929981504960[5] = 0;
   out_6726501929981504960[6] = 0;
   out_6726501929981504960[7] = 0;
   out_6726501929981504960[8] = 0;
   out_6726501929981504960[9] = 0;
   out_6726501929981504960[10] = 1.0;
   out_6726501929981504960[11] = 0;
   out_6726501929981504960[12] = 0;
   out_6726501929981504960[13] = 0;
   out_6726501929981504960[14] = 0;
   out_6726501929981504960[15] = 0;
   out_6726501929981504960[16] = 0;
   out_6726501929981504960[17] = 0;
   out_6726501929981504960[18] = 0;
   out_6726501929981504960[19] = 0;
   out_6726501929981504960[20] = 1.0;
   out_6726501929981504960[21] = 0;
   out_6726501929981504960[22] = 0;
   out_6726501929981504960[23] = 0;
   out_6726501929981504960[24] = 0;
   out_6726501929981504960[25] = 0;
   out_6726501929981504960[26] = 0;
   out_6726501929981504960[27] = 0;
   out_6726501929981504960[28] = 0;
   out_6726501929981504960[29] = 0;
   out_6726501929981504960[30] = 1.0;
   out_6726501929981504960[31] = 0;
   out_6726501929981504960[32] = 0;
   out_6726501929981504960[33] = 0;
   out_6726501929981504960[34] = 0;
   out_6726501929981504960[35] = 0;
   out_6726501929981504960[36] = 0;
   out_6726501929981504960[37] = 0;
   out_6726501929981504960[38] = 0;
   out_6726501929981504960[39] = 0;
   out_6726501929981504960[40] = 1.0;
   out_6726501929981504960[41] = 0;
   out_6726501929981504960[42] = 0;
   out_6726501929981504960[43] = 0;
   out_6726501929981504960[44] = 0;
   out_6726501929981504960[45] = 0;
   out_6726501929981504960[46] = 0;
   out_6726501929981504960[47] = 0;
   out_6726501929981504960[48] = 0;
   out_6726501929981504960[49] = 0;
   out_6726501929981504960[50] = 1.0;
   out_6726501929981504960[51] = 0;
   out_6726501929981504960[52] = 0;
   out_6726501929981504960[53] = 0;
   out_6726501929981504960[54] = 0;
   out_6726501929981504960[55] = 0;
   out_6726501929981504960[56] = 0;
   out_6726501929981504960[57] = 0;
   out_6726501929981504960[58] = 0;
   out_6726501929981504960[59] = 0;
   out_6726501929981504960[60] = 1.0;
   out_6726501929981504960[61] = 0;
   out_6726501929981504960[62] = 0;
   out_6726501929981504960[63] = 0;
   out_6726501929981504960[64] = 0;
   out_6726501929981504960[65] = 0;
   out_6726501929981504960[66] = 0;
   out_6726501929981504960[67] = 0;
   out_6726501929981504960[68] = 0;
   out_6726501929981504960[69] = 0;
   out_6726501929981504960[70] = 1.0;
   out_6726501929981504960[71] = 0;
   out_6726501929981504960[72] = 0;
   out_6726501929981504960[73] = 0;
   out_6726501929981504960[74] = 0;
   out_6726501929981504960[75] = 0;
   out_6726501929981504960[76] = 0;
   out_6726501929981504960[77] = 0;
   out_6726501929981504960[78] = 0;
   out_6726501929981504960[79] = 0;
   out_6726501929981504960[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_4014964142285131911) {
   out_4014964142285131911[0] = state[0];
   out_4014964142285131911[1] = state[1];
   out_4014964142285131911[2] = state[2];
   out_4014964142285131911[3] = state[3];
   out_4014964142285131911[4] = state[4];
   out_4014964142285131911[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_4014964142285131911[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_4014964142285131911[7] = state[7];
   out_4014964142285131911[8] = state[8];
}
void F_fun(double *state, double dt, double *out_2355657713517530665) {
   out_2355657713517530665[0] = 1;
   out_2355657713517530665[1] = 0;
   out_2355657713517530665[2] = 0;
   out_2355657713517530665[3] = 0;
   out_2355657713517530665[4] = 0;
   out_2355657713517530665[5] = 0;
   out_2355657713517530665[6] = 0;
   out_2355657713517530665[7] = 0;
   out_2355657713517530665[8] = 0;
   out_2355657713517530665[9] = 0;
   out_2355657713517530665[10] = 1;
   out_2355657713517530665[11] = 0;
   out_2355657713517530665[12] = 0;
   out_2355657713517530665[13] = 0;
   out_2355657713517530665[14] = 0;
   out_2355657713517530665[15] = 0;
   out_2355657713517530665[16] = 0;
   out_2355657713517530665[17] = 0;
   out_2355657713517530665[18] = 0;
   out_2355657713517530665[19] = 0;
   out_2355657713517530665[20] = 1;
   out_2355657713517530665[21] = 0;
   out_2355657713517530665[22] = 0;
   out_2355657713517530665[23] = 0;
   out_2355657713517530665[24] = 0;
   out_2355657713517530665[25] = 0;
   out_2355657713517530665[26] = 0;
   out_2355657713517530665[27] = 0;
   out_2355657713517530665[28] = 0;
   out_2355657713517530665[29] = 0;
   out_2355657713517530665[30] = 1;
   out_2355657713517530665[31] = 0;
   out_2355657713517530665[32] = 0;
   out_2355657713517530665[33] = 0;
   out_2355657713517530665[34] = 0;
   out_2355657713517530665[35] = 0;
   out_2355657713517530665[36] = 0;
   out_2355657713517530665[37] = 0;
   out_2355657713517530665[38] = 0;
   out_2355657713517530665[39] = 0;
   out_2355657713517530665[40] = 1;
   out_2355657713517530665[41] = 0;
   out_2355657713517530665[42] = 0;
   out_2355657713517530665[43] = 0;
   out_2355657713517530665[44] = 0;
   out_2355657713517530665[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_2355657713517530665[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_2355657713517530665[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2355657713517530665[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_2355657713517530665[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_2355657713517530665[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_2355657713517530665[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_2355657713517530665[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_2355657713517530665[53] = -9.8000000000000007*dt;
   out_2355657713517530665[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_2355657713517530665[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_2355657713517530665[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2355657713517530665[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2355657713517530665[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_2355657713517530665[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_2355657713517530665[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_2355657713517530665[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_2355657713517530665[62] = 0;
   out_2355657713517530665[63] = 0;
   out_2355657713517530665[64] = 0;
   out_2355657713517530665[65] = 0;
   out_2355657713517530665[66] = 0;
   out_2355657713517530665[67] = 0;
   out_2355657713517530665[68] = 0;
   out_2355657713517530665[69] = 0;
   out_2355657713517530665[70] = 1;
   out_2355657713517530665[71] = 0;
   out_2355657713517530665[72] = 0;
   out_2355657713517530665[73] = 0;
   out_2355657713517530665[74] = 0;
   out_2355657713517530665[75] = 0;
   out_2355657713517530665[76] = 0;
   out_2355657713517530665[77] = 0;
   out_2355657713517530665[78] = 0;
   out_2355657713517530665[79] = 0;
   out_2355657713517530665[80] = 1;
}
void h_25(double *state, double *unused, double *out_6466845240886339756) {
   out_6466845240886339756[0] = state[6];
}
void H_25(double *state, double *unused, double *out_227966644233802315) {
   out_227966644233802315[0] = 0;
   out_227966644233802315[1] = 0;
   out_227966644233802315[2] = 0;
   out_227966644233802315[3] = 0;
   out_227966644233802315[4] = 0;
   out_227966644233802315[5] = 0;
   out_227966644233802315[6] = 1;
   out_227966644233802315[7] = 0;
   out_227966644233802315[8] = 0;
}
void h_24(double *state, double *unused, double *out_8082310701426017685) {
   out_8082310701426017685[0] = state[4];
   out_8082310701426017685[1] = state[5];
}
void H_24(double *state, double *unused, double *out_756099226607511353) {
   out_756099226607511353[0] = 0;
   out_756099226607511353[1] = 0;
   out_756099226607511353[2] = 0;
   out_756099226607511353[3] = 0;
   out_756099226607511353[4] = 1;
   out_756099226607511353[5] = 0;
   out_756099226607511353[6] = 0;
   out_756099226607511353[7] = 0;
   out_756099226607511353[8] = 0;
   out_756099226607511353[9] = 0;
   out_756099226607511353[10] = 0;
   out_756099226607511353[11] = 0;
   out_756099226607511353[12] = 0;
   out_756099226607511353[13] = 0;
   out_756099226607511353[14] = 1;
   out_756099226607511353[15] = 0;
   out_756099226607511353[16] = 0;
   out_756099226607511353[17] = 0;
}
void h_30(double *state, double *unused, double *out_8342449304569189510) {
   out_8342449304569189510[0] = state[4];
}
void H_30(double *state, double *unused, double *out_357305591377042385) {
   out_357305591377042385[0] = 0;
   out_357305591377042385[1] = 0;
   out_357305591377042385[2] = 0;
   out_357305591377042385[3] = 0;
   out_357305591377042385[4] = 1;
   out_357305591377042385[5] = 0;
   out_357305591377042385[6] = 0;
   out_357305591377042385[7] = 0;
   out_357305591377042385[8] = 0;
}
void h_26(double *state, double *unused, double *out_5102621501479516461) {
   out_5102621501479516461[0] = state[7];
}
void H_26(double *state, double *unused, double *out_3969469963107858539) {
   out_3969469963107858539[0] = 0;
   out_3969469963107858539[1] = 0;
   out_3969469963107858539[2] = 0;
   out_3969469963107858539[3] = 0;
   out_3969469963107858539[4] = 0;
   out_3969469963107858539[5] = 0;
   out_3969469963107858539[6] = 0;
   out_3969469963107858539[7] = 1;
   out_3969469963107858539[8] = 0;
}
void h_27(double *state, double *unused, double *out_2515123931120501009) {
   out_2515123931120501009[0] = state[3];
}
void H_27(double *state, double *unused, double *out_2532068903177467296) {
   out_2532068903177467296[0] = 0;
   out_2532068903177467296[1] = 0;
   out_2532068903177467296[2] = 0;
   out_2532068903177467296[3] = 1;
   out_2532068903177467296[4] = 0;
   out_2532068903177467296[5] = 0;
   out_2532068903177467296[6] = 0;
   out_2532068903177467296[7] = 0;
   out_2532068903177467296[8] = 0;
}
void h_29(double *state, double *unused, double *out_9160784916238699671) {
   out_9160784916238699671[0] = state[1];
}
void H_29(double *state, double *unused, double *out_4245431630047018329) {
   out_4245431630047018329[0] = 0;
   out_4245431630047018329[1] = 1;
   out_4245431630047018329[2] = 0;
   out_4245431630047018329[3] = 0;
   out_4245431630047018329[4] = 0;
   out_4245431630047018329[5] = 0;
   out_4245431630047018329[6] = 0;
   out_4245431630047018329[7] = 0;
   out_4245431630047018329[8] = 0;
}
void h_28(double *state, double *unused, double *out_2486549336540344636) {
   out_2486549336540344636[0] = state[0];
}
void H_28(double *state, double *unused, double *out_9118913426593002713) {
   out_9118913426593002713[0] = 1;
   out_9118913426593002713[1] = 0;
   out_9118913426593002713[2] = 0;
   out_9118913426593002713[3] = 0;
   out_9118913426593002713[4] = 0;
   out_9118913426593002713[5] = 0;
   out_9118913426593002713[6] = 0;
   out_9118913426593002713[7] = 0;
   out_9118913426593002713[8] = 0;
}
void h_31(double *state, double *unused, double *out_6066165806152463487) {
   out_6066165806152463487[0] = state[8];
}
void H_31(double *state, double *unused, double *out_197320682356841887) {
   out_197320682356841887[0] = 0;
   out_197320682356841887[1] = 0;
   out_197320682356841887[2] = 0;
   out_197320682356841887[3] = 0;
   out_197320682356841887[4] = 0;
   out_197320682356841887[5] = 0;
   out_197320682356841887[6] = 0;
   out_197320682356841887[7] = 0;
   out_197320682356841887[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_6486958562498374070) {
  err_fun(nom_x, delta_x, out_6486958562498374070);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_4487160442454099930) {
  inv_err_fun(nom_x, true_x, out_4487160442454099930);
}
void car_H_mod_fun(double *state, double *out_6726501929981504960) {
  H_mod_fun(state, out_6726501929981504960);
}
void car_f_fun(double *state, double dt, double *out_4014964142285131911) {
  f_fun(state,  dt, out_4014964142285131911);
}
void car_F_fun(double *state, double dt, double *out_2355657713517530665) {
  F_fun(state,  dt, out_2355657713517530665);
}
void car_h_25(double *state, double *unused, double *out_6466845240886339756) {
  h_25(state, unused, out_6466845240886339756);
}
void car_H_25(double *state, double *unused, double *out_227966644233802315) {
  H_25(state, unused, out_227966644233802315);
}
void car_h_24(double *state, double *unused, double *out_8082310701426017685) {
  h_24(state, unused, out_8082310701426017685);
}
void car_H_24(double *state, double *unused, double *out_756099226607511353) {
  H_24(state, unused, out_756099226607511353);
}
void car_h_30(double *state, double *unused, double *out_8342449304569189510) {
  h_30(state, unused, out_8342449304569189510);
}
void car_H_30(double *state, double *unused, double *out_357305591377042385) {
  H_30(state, unused, out_357305591377042385);
}
void car_h_26(double *state, double *unused, double *out_5102621501479516461) {
  h_26(state, unused, out_5102621501479516461);
}
void car_H_26(double *state, double *unused, double *out_3969469963107858539) {
  H_26(state, unused, out_3969469963107858539);
}
void car_h_27(double *state, double *unused, double *out_2515123931120501009) {
  h_27(state, unused, out_2515123931120501009);
}
void car_H_27(double *state, double *unused, double *out_2532068903177467296) {
  H_27(state, unused, out_2532068903177467296);
}
void car_h_29(double *state, double *unused, double *out_9160784916238699671) {
  h_29(state, unused, out_9160784916238699671);
}
void car_H_29(double *state, double *unused, double *out_4245431630047018329) {
  H_29(state, unused, out_4245431630047018329);
}
void car_h_28(double *state, double *unused, double *out_2486549336540344636) {
  h_28(state, unused, out_2486549336540344636);
}
void car_H_28(double *state, double *unused, double *out_9118913426593002713) {
  H_28(state, unused, out_9118913426593002713);
}
void car_h_31(double *state, double *unused, double *out_6066165806152463487) {
  h_31(state, unused, out_6066165806152463487);
}
void car_H_31(double *state, double *unused, double *out_197320682356841887) {
  H_31(state, unused, out_197320682356841887);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
