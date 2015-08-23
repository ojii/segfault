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

static struct PyModuleDef segfaultmodule = {
    PyModuleDef_HEAD_INIT,
    "segfault",
    NULL,
    -1,
    SegfaultMethods
};

PyMODINIT_FUNC
PyInit_segfault(void)
{
    return PyModule_Create(&segfaultmodule);
}
