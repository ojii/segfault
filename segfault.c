#include <Python.h>

static PyObject *segfault_segfault(PyObject *self, PyObject *args)
{
    // According to StackOverflow, the next line will segfault
    *(int*)0=0;
    return PyLong_FromLong(1);
}

static PyMethodDef SegfaultMethods[] = {
    {"segfault", segfault_segfault, METH_VARARGS, "Segfault"},
    {NULL, NULL, 0, NULL}
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef segfaultmodule = {
    PyModuleDef_HEAD_INIT,
    "segfault",
    NULL,
    -1,
    SegfaultMethods
};

PyObject * PyInit_segfault(void)

#else

void initsegfault(void)
#endif
{
#if PY_MAJOR_VERSION >= 3
    PyObject *module = PyModule_Create(&segfaultmodule);
#else
    Py_InitModule("segfault", SegfaultMethods);
#endif
#if PY_MAJOR_VERSION >= 3
    return module;
#endif
}
