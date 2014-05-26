#if !defined input_h

#define input_h

const int maxBuf = 100;

const int tokNumber = 1;
const int tokError = 2;

class Input {
public:
	Input();
	int getToken() const {
		return _token;
	}
	int number() const;
private:
	int _token;
	char _buf[maxBuf];
};

#endif