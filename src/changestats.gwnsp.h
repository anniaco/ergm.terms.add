#ifndef CHANGESTATS_H
#define CHANGESTATS_H

#include "edgetree.h"
#include "changestat.h"

#define ESPUTP 0
#define ESPOTP 1
#define ESPITP 2
#define ESPRTP 3
#define ESPOSP 4
#define ESPISP 5

/*DSP calculation functions*/
void dspUTP_calc(Edge ntoggles, Vertex *tails, Vertex *heads, ModelTerm *mtp, Network *nwp, int nd, double *dvec, double *cs);
void dspOTP_calc(Edge ntoggles, Vertex *tails, Vertex *heads, ModelTerm *mtp, Network *nwp, int nd, double *dvec, double *cs);
void dspITP_calc(Edge ntoggles, Vertex *tails, Vertex *heads, ModelTerm *mtp, Network *nwp, int nd, double *dvec, double *cs);
void dspRTP_calc(Edge ntoggles, Vertex *tails, Vertex *heads, ModelTerm *mtp, Network *nwp, int nd, double *dvec, double *cs);
void dspOSP_calc(Edge ntoggles, Vertex *tails, Vertex *heads, ModelTerm *mtp, Network *nwp, int nd, double *dvec, double *cs);
void dspISP_calc(Edge ntoggles, Vertex *tails, Vertex *heads, ModelTerm *mtp, Network *nwp, int nd, double *dvec, double *cs);

/*ESP calculation functions*/
void espUTP_calc(Edge ntoggles, Vertex *tails, Vertex *heads, ModelTerm *mtp, Network *nwp, int nd, double *dvec, double *cs);
void espOTP_calc(Edge ntoggles, Vertex *tails, Vertex *heads, ModelTerm *mtp, Network *nwp, int nd, double *dvec, double *cs);
void espITP_calc(Edge ntoggles, Vertex *tails, Vertex *heads, ModelTerm *mtp, Network *nwp, int nd, double *dvec, double *cs);
void espRTP_calc(Edge ntoggles, Vertex *tails, Vertex *heads, ModelTerm *mtp, Network *nwp, int nd, double *dvec, double *cs);
void espOSP_calc(Edge ntoggles, Vertex *tails, Vertex *heads, ModelTerm *mtp, Network *nwp, int nd, double *dvec, double *cs);
void espISP_calc(Edge ntoggles, Vertex *tails, Vertex *heads, ModelTerm *mtp, Network *nwp, int nd, double *dvec, double *cs);


/*Changescore functions*/
D_CHANGESTAT_FN(d_dnsp);
D_CHANGESTAT_FN(d_dgwnsp);

#endif
