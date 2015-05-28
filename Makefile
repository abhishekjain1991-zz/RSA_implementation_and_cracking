# Build the RSA assignment
RSA:	RSA.cc
	$(CXX) -g -o RSA RSA.cc -lgmp -lgmpxx
