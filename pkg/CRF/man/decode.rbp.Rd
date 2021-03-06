% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/decode.R
\name{decode.rbp}
\alias{decode.rbp}
\title{Decoding method using residual belief propagation}
\usage{
decode.rbp(crf, max.iter = 10000, cutoff = 1e-04, verbose = 0)
}
\arguments{
\item{crf}{The CRF}

\item{max.iter}{The maximum allowed iterations of termination criteria}

\item{cutoff}{The convergence cutoff of termination criteria}

\item{verbose}{Non-negative integer to control the tracing informtion in algorithm}
}
\value{
This function will return the most likely configuration, which is a vector of length \code{crf$n.nodes}.
}
\description{
Computing the most likely configuration for CRF
}
\details{
Approximate decoding using max-product residual belief propagation
}
\examples{

library(CRF)
data(Small)
d <- decode.rbp(Small$crf)

}
