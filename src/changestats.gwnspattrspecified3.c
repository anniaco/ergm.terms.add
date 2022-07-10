/*  
 *  This software is distributed under the GPL-3 license.  It is free,
 *  open source, and has the attribution requirements (GPL Section 7) at
 *  http://statnet.org/attribution
 *
 */

#include "d_gwnspattrspecified3.h"

CHANGESTAT_FN(d_gwnspattrspecified3){
  Edge e, f;
  int i, echange, ochange;
  int L2tu, L2uh, L2th;
  Vertex tail, head, u, v;
  double alpha, oneexpa, cumchange, p1attr, p2attr, battr;
  
  /* *** don't forget tail -> head */    
  CHANGE_STAT[0] = 0.0;
  alpha = INPUT_PARAM[N_NODES + N_NODES + 3];
  oneexpa = 1.0-exp(-alpha);
  
  p1attr = INPUT_PARAM[N_NODES + N_NODES];
  p2attr = INPUT_PARAM[N_NODES + N_NODES + 1];
  battr = INPUT_PARAM[N_NODES + N_NODES + 2];
  
  FOR_EACH_TOGGLE(i){
    tail = TAIL(i); 
    head = HEAD(i);
    
    cumchange=0.0;
    ochange = IS_OUTEDGE(tail, head) ? -1 : 0;
    echange = 2*ochange + 1;
    
    /* step through outedges of head */
    STEP_THROUGH_OUTEDGES(head, e, u){
      if (u != tail && INPUT_PARAM[tail - 1] == p1attr && INPUT_PARAM[u-1] == p2attr && INPUT_PARAM[N_NODES + head - 1] == battr){
        L2tu=ochange;
        /* step through outedges of u */
        STEP_THROUGH_INEDGES(u, f, v){
          if(v != head && INPUT_PARAM[N_NODES + v - 1] == battr && IS_OUTEDGE(tail, v)) L2tu++;
        }
        cumchange += pow(oneexpa,(double)L2tu);
      }
    }
    
    /* step through inedges of tail */
    STEP_THROUGH_INEDGES(tail, e, v){
      if (v != head && INPUT_PARAM[v-1] == p1attr && INPUT_PARAM[head - 1] == p2attr && INPUT_PARAM[N_NODES + tail - 1] == battr){
        L2uh=ochange;
        /* step through outedges of v */
        STEP_THROUGH_OUTEDGES(v, f, u){
          if(u != tail && INPUT_PARAM[N_NODES + u - 1] == battr && IS_INEDGE(head, u)) L2uh++;
        }
        cumchange += pow(oneexpa,(double)L2uh);
      }
    }
    
    cumchange  = echange*cumchange;
    (CHANGE_STAT[0]) += cumchange;
    TOGGLE_IF_MORE_TO_COME(i);
  }
  
  UNDO_PREVIOUS_TOGGLES(i);
  
  alpha = INPUT_PARAM[N_NODES+N_NODES+3];
  oneexpa = 1.0-exp(-alpha);
  
  /* *** don't forget tail -> head */    
  FOR_EACH_TOGGLE(i){
    tail = TAIL(i); 
    head = HEAD(i);
    cumchange=0.0;
    L2th=0;
    ochange = IS_OUTEDGE(tail, head) ? -1 : 0;
    echange = 2*ochange + 1;
    
    STEP_THROUGH_OUTEDGES(head, e, u){
      if (u != tail && INPUT_PARAM[tail-1] == p1attr && INPUT_PARAM[u-1] == p2attr && INPUT_PARAM[N_NODES + head - 1] == battr && IS_OUTEDGE(tail, u)){
        L2tu=ochange;
        /* step through inedges of u */
        STEP_THROUGH_INEDGES(u, f, v){
          if(INPUT_PARAM[N_NODES + v - 1] == battr && IS_OUTEDGE(tail, v)) L2tu++;
        }
        cumchange += pow(oneexpa,(double)L2tu);
      }
    }
    
    /* step through inedges of head */
    STEP_THROUGH_INEDGES(head, e, u){
      if (INPUT_PARAM[tail-1] == p1attr && INPUT_PARAM[head-1] == p2attr && INPUT_PARAM[N_NODES + u - 1] == battr && IS_OUTEDGE(tail, u)){
        L2th++;
      }
      if (INPUT_PARAM[u-1] == p1attr && INPUT_PARAM[head-1] == p2attr && INPUT_PARAM[N_NODES + tail - 1] == battr && IS_OUTEDGE(u, tail)){
        L2uh=ochange;
        /* step through outedges of u */
        STEP_THROUGH_OUTEDGES(u, f, v){
          if(INPUT_PARAM[N_NODES + v - 1] == battr && IS_OUTEDGE(v, head)) L2uh++;
        }
        cumchange += pow(oneexpa,(double)L2uh) ;
      }
    }
    
    if(alpha < 100.0){
      cumchange += exp(alpha)*(1.0-pow(oneexpa,(double)L2th)) ;
    }else{
      cumchange += (double)L2th;
    }
    cumchange  = echange*cumchange;
    (CHANGE_STAT[0]) -= cumchange;
    TOGGLE_IF_MORE_TO_COME(i);
  }
  UNDO_PREVIOUS_TOGGLES(i);
  
}
