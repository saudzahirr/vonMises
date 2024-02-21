cd src/lib/
rm -rf *.so
g++ -fPIC -shared eigen.cpp rayleigh_quotient.cpp utils.cpp von_mises.cpp logger.cpp -o libeigen.so -fopenmp
cd ../../
