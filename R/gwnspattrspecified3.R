
InitErgmTerm.gwnspattrspecified3 <- function(nw, arglist, ...) {
  a <- check.ErgmTerm (nw, arglist, directed=TRUE, 
                       varnames = c("pattrname","p1keep","p2keep","battrname","bkeep","alpha"),
                       vartypes = c("character","numeric","numeric","character","numeric","numeric"),
                       defaultvalues = list(NULL,NULL,NULL,NULL,NULL,NULL),
                       required = c(TRUE, TRUE, TRUE, TRUE,TRUE, TRUE))  
  n <- network.size(nw)
  
  pnodecov <- get.node.attr(nw,a$pattrname)
  bnodecov <- get.node.attr(nw,a$battrname)
  
  p1u<-sort(unique(pnodecov))
  if(any(is.na(pnodecov))){ p1u<-c(p1u,NA) }
  pnodecov <- match(pnodecov,p1u,nomatch=length(p1u)+1)
  
  bu<-sort(unique(bnodecov))
  if(any(is.na(bnodecov))){ bu<-c(bu,NA) }
  bnodecov <- match(bnodecov,bu,nomatch=length(bu)+1)
  
  u <- c(a$p1keep,a$p2keep,a$bkeep,a$alpha)
  
  coef.names <- paste0("gwnspattrspecified3.", a$pattrname, ".", p1u[a$p1keep], ">",a$battrname, ".", bu[a$bkeep], ">", a$pattrname, ".", p1u[a$p2keep],".a:",a$alpha)
  list(name = "gwnspattrspecified3", coef.names = coef.names, #name and coef.names: required
       inputs = c(pnodecov,bnodecov,u), minval=0)
}


