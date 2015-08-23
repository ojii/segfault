from distutils.core import setup, Extension

segfault = Extension(
    "segfault",
    sources=["segfault.c"],
)
setup(
    name="python-segfault", 
    version="1",
    description="Segfaults your Python",
    ext_modules=[segfault]
)
