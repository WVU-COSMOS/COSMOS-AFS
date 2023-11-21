from setuptools import find_packages
from setuptools import setup

setup(
    name='cosmos_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('cosmos_interfaces', 'cosmos_interfaces.*')),
)
