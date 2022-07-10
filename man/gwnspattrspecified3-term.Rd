\name{gwnspattrspecified3-term}
\alias{gwnspattrspecified3}
\docType{methods}
\title{Geometrically weighted non-edgewise shared partner terms with certain attribute values}
\description{
  Geometrically weighted non-edgewise shared partner distribution to test for attribute-based brokerage. 
  These terms are closely related to the \code{gwnsp} term in the \pkg{ergm} package, with adaptations to test for nodal attributes of pendants and broker.
  It can be used to test vertical brokerage, and measures the number of nodes that complete a two-path between pairs of pendant nodes that have heterogenous attributes. 
}
%\usage{
%terms.ergm()

%}
%\arguments{
%\item{\dots}{Specific to the model term.}
%}

\details{

\code{gwnspattrspecified3((pattrname=NULL,p1keep=NULL,p2keep=NULL,battrname=NULL,bkeep=NULL,alpha=NULL) (binary) (directed)}

Geometrically weighted nonedgewise shared partner distribution between nodes with different attributes in the network

}

\seealso{
  See also \code{\link[ergm]{gwnsp}} term. 
}


%\value{\code{\link{ergm}} returns an object of class 'ergm' that is a list.
%}
\references{


Wang, P., Sharpe, K., Robins, G. L., and Pattison, P. E. (2009). Exponential random graph (p*) models for affiliation networks. Social Networks. 31(1): 12-25.

}

\author{
Matthew Hamilton  \email{matthewlhamilton@gmail.com}
}

\examples{
require(ergm.terms.contrib)
# create example data
bel <- data.frame(actor = c("a","a","a","b","b","b","b","c","c","c","c"), 
                  event = c("e1","e2","e3","e3","e1","e4","e5","e3","e1","e4","e6"))
bnet <- network(bel,bipartite=3,directed=FALSE)

# how many actor (first mode) dyads have ANY shared partners?
summary(bnet ~ gwb1nsp(0,TRUE))

# calculate for 2nd mode, using non-extreme alphas 
# to weight each additional shared partner less than the one before
summary(bnet ~ gwb2nsp(.5,TRUE))

}
\keyword{models}
