#include <iostream>
#include <string>

class solution {
public:
  bool isScramble(const std::string & s1, const std::string & s2) {
    if (s1.size() != s2.size())
      return false;
    else {
      if (s1.size() == 1) {
	if (!s1.compare(s2))
	  return true;
	else
	  return false;
      }
      else if (s1.size()%2 == 0) {
	size_t mid = s1.size()/2;
	return (isScramble(s1.substr(0,mid), s2.substr(0,mid)) && isScramble(s1.substr(mid), s2.substr(mid))) || (isScramble(s1.substr(0,mid), s2.substr(mid))&&isScramble(s1.substr(mid), s2.substr(0,mid)));
      }
      else {
	size_t mid = s1.size()/2;
	return (isScramble(s1.substr(0,mid), s2.substr(0,mid)) && isScramble(s1.substr(mid), s2.substr(mid))) || (isScramble(s1.substr(0,mid+1), s2.substr(0,mid+1)) && isScramble(s1.substr(mid+1), s2.substr(mid+1))) || (isScramble(s1.substr(0,mid), s2.substr(mid+1)) && isScramble(s1.substr(mid), s2.substr(0, mid+1))) || (isScramble(s1.substr(0,mid+1), s2.substr(mid)) && isScramble(s1.substr(mid+1), s2.substr(0, mid)));
      }
    }
  }
};

int main() {
  std::string s{"great"}, t{"rgate"};
  // std::string s{"rgeat"}, t{"rgate"};

  solution soln;
  auto scramble = soln.isScramble(s,t);
  std::cout << s << (scramble ? " is " : " is NOT ") << "a scrambled string of " << t << std::endl;
}
