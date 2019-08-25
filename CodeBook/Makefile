.PHONY:test
all:
	@g++ gen.cpp -o .gen.out
	@./.gen.out
	@rm .gen.out

test:
	@g++ gen.cpp -o .gen.out
	@./.gen.out test
	@rm .gen.out

check:
	@g++ gen.cpp -o .gen.out
	@./.gen.out check
	@rm .gen.out
