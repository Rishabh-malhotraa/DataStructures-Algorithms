/*
🧠 BOOST STRING ALGO PRACTICE QUESTIONS

🔹 1. Case-Insensitive Match

Given a list of HTTP headers, find if it contains "Content-Type" (case-insensitive).

Input:

std::vector<std::string> headers = {"host", "accept", "content-type", "user-agent"};

Task:
Use a Boost function to check if "Content-Type" exists, case-insensitively.

⸻

🔹 2. Trim + Check Prefix

A user sends a string "   /home/user/docs  " from a web UI. You want to:

	1.	Trim the string
	2.	Check if it starts with "/home/"

Task:
Return true if the trimmed path starts with "/home/".

⸻

🔹 3. Split CSV + Clean Tokens

Split this string into parts and trim each one:

std::string line = "  apple , banana,carrot  ,  ";

Expected Output (vector):

["apple", "banana", "carrot"]

Bonus: Ignore empty or whitespace-only parts.

⸻

🔹 4. Normalize Casing

Convert the following string into lowercase and replace all spaces with underscores:

std::string tag = "Error Logging System";

Expected Output:

"error_logging_system"


⸻

🔹 5. Find & Extract Parameter

From a config line:

std::string line = "user.name=admin";

Task:
Extract just "admin" using Boost string functions.

⸻

🔹 6. Join Vector Elements

You have:

std::vector<std::string> values = {"one", "two", "three"};

Task:
Join them into: "one|two|three"

⸻

🔹 7. Remove HTML-like Tags

Input:

std::string raw = "<b>Hello</b>";

Task:
Remove <b> and </b> using Boost string functions.

Expected Output:

Hello


⸻

🔹 8. Case-Insensitive Substring Check

Check if the string:

std::string text = "Boost makes C++ better";

contains "c++" — case-insensitive.

⸻

🔹 9. Replace Path Separators

Replace all \ with / in:

std::string path = "C:\\Users\\Rishabh\\Documents";

Expected Output:

C:/Users/Rishabh/Documents


⸻

🔹 10. Tokenize with Multiple Delimiters

Tokenize this string by ;, , or | and remove empty tokens:

std::string messy = "one;;two,|three||,four;";

Expected Output:

["one", "two", "three", "four"]


⸻

Would you like:
	•	Solutions to these?
	•	A code file with all problems scaffolded?
	•	Harder challenges with boost::regex or locale?

Let’s keep sharpening.
*/

#include <bits/stdc++.h>



