#include <pybind11/pybind11.h>

#include "slam2d/types_slam2d.h"



namespace py = pybind11;
using namespace pybind11::literals;


namespace g2o {

void declareTypes(py::module & m) {

    // slam2d
    declareTypesSlam2d(m);
    
}

}  // end namespace g2o