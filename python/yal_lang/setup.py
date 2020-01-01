long_desc = open('README.md','r').read()

from setuptools import setup

setup(
    name = "YalLang",
    version = '1.0.2.1',
    url = "https://github.com/ARACADERISE/extras/tree/master/python/yal_lang",
    license = "MIT License",
    author = "ARACADERISE",
    description = "Lightweight version of Python, easily compiled, easily written.",
    long_description = long_desc,
    packages = [],
    include_package_data = True,
    platforms = "LINUX",
    install_requires = ['colorama'],
    classifiers = [
        "Development Status :: 1 - Beta",
        "Environment :: Console",
        "License :: OSI Approved :: MIT License",
        "Operating System :: POSIX :: Linux",
        "Programming Language :: Python :: 3.8",
        "Topic :: Programming Language/Coding",
        "Topic :: Development :: Application development",
        "Topic :: Development"
    ]
)
