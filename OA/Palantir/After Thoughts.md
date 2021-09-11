# OA for Palantir

_I should not put this on GitHub LOL \<But I don't suspect anyone would actually see this>; If someone does, then Hi Stalker, at least drop a star at the repo lol_

## Subtask

- Just check if the hostname is different if the domain name is (ignore if hostname == hostname of original)
- Identify slightly different characters in the domain name
- Identify if a swap has been made in the original company name and the fake company name
  - subcase if palanti.rbiz is a TC of palantir.com because if `.` and the first letter of the host are swapped
    you are required to again run task one the same

### How I Faired

- **1st task ALL TC Passed**

  - {I got a WA because of using sets rather than multimap}
  - I took more time than I should have

- **2nd Task ALL TC Passed**

  - I did took care of the case of nodes being undirected rather than directed i.e a -> {b, c} then b-> {a, c} & c-> {b ,a}
  - I had a typo of 1 to l, but that did not take a lot of time to figure out because I suspected
    it to be an error in the entry of the map because I got just 1 WA for all TC

- **3rd Task 5/9 TC Passed**
  - this was the easiest task, but the second subpart took me a lot of time to understand
    about what the question is actually saying
  - You need to just check if there was one swap
    - the second subpart was also very, very easy
    - but I figured it out when I only had 3 minutes remaining & I legit found the last typo when I had 9 seconds remaining
    - not that it mattered much. It just improved the TC by 1
    - I know why the other TC would have failed. What I suspect is that I did not take care of duplicates
      I should have just used a set and then a vector urgh
    - either that or there was some logic error, but I doubt it.

---

## EDIT (16-08-21)

I got the interview call :)

---
