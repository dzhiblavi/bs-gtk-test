#include <boost/python.hpp>

#include "python/greet.h"

namespace python {

BOOST_PYTHON_MODULE(py_greet)
{
  boost::python::def("greet", greet);
}

}  // namespace python
