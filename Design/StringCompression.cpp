#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using namespace boost::algorithm;

class StringCompression {
public:
    string compress(string rawInput, int minor_parts) {
        vector<string> segments;
        split(segments, rawInput, boost::is_any_of("/"));

        for (string &segment : segments) {
            vector<string> blocks, compressed;
            split(blocks, segment, boost::is_any_of("."));

            int keep = max(0, minor_parts - 1);
            for (int i = 0; i < min((int)blocks.size(), keep); i++) {
                compressed.push_back(compress_token(blocks[i]));
            }

            string remaining;
            for (int j = keep; j < (int)blocks.size(); j++) {
                remaining += blocks[j];
            }

            if (!remaining.empty()) {
                compressed.push_back(compress_token(remaining));
            }

            segment = join(compressed, ".");
        }

        return join(segments, "/");
    }

private:
    string compress_token(const string& s) {
        int n = s.size();
        if (n <= 2) return s;
        return s[0] + to_string(n - 2) + s[n - 1];
    }
};


void run_test(const std::string& input, int m, const std::string& expected, const std::string& actual, const std::string& test_name) {
  if (expected != actual) {
    std::cerr << "❌ Test Failed: " << test_name << "\n";
    std::cerr << "Input     : " << input << "\n";
    std::cerr << "Expected  : " << expected << "\n";
    std::cerr << "Actual    : " << actual << "\n";
    assert(false && "Test failed");  // Optional if you want hard stops
  }
  else {
    std::cout << "✅ Test Passed: " << test_name << std::endl;
  }
}

int main() {
  StringCompression sc;

  {
    std::string input = "stripe.com/payments/checkout/customer.maria.doe";
    int m = 2;
    std::string expected = "s4e.c1m/p6s/c6t/c6r.m6e";
    std::string actual = sc.compress(input, m);
    run_test(input, m, expected, actual, "Stripe Path Compression");
  }

  {
    std::string input = "a.b.c.d.e.f";
    int m = 3;
    std::string expected = "a.b.c2f";  // Update once you're sure of compression rules
    std::string actual = sc.compress(input, m);
    run_test(input, m, expected, actual, "Simple Dot Path Compression");
  }

  {
    std::string input = "section/how.to.write.a.java.program.in.one.day";
    int m = 5;
    std::string expected = "s5n/h1w.to.w3e.a.j17y";  // Verify based on your rules
    std::string actual = sc.compress(input, m);
    run_test(input, m, expected, actual, "Long Sentence Compression");
  }

  std::cout << "🎉 All tests completed!" << std::endl;
  return 0;
}