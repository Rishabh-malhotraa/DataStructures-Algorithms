# Build [tech.trell.co](http://tech.trell.co/) / Medium website

## **Overview**

With the onset of tech blogs, the availability of refined engineering techniques has become easier day by day. One can document an their leamings and give back to the community. To do this, Ire needs your help to build them a medium-like blogging website where Trell's engineers can share their learnings.

The blogging website should have the following deliverables which you will be judged upon in the given time frame:

1. **User Registration:**
   1. This page should take in the user's handle name, full name and password to create a new user.
      Every user should have 3 'interests" tags [Can be anything you wish, photography, technology, etc]
2. **Basic Feed Page:**

   _(Note You can assume any logged in user for now, no need for login page.)_

   1. This page should display 10 recent posts for the logged in user with matching post lags as that of user (Even a one tag matches, the feed should load that post, recent posts should get preference). 2. Every post should be linked to their own reading page endpoint. 3. Whenever a reading page endpoint is loaded. it should store timestamp, userhandle, user tags in the backend.

3. **Blog Post Creation**
   1. The logged in user should be able to create a blog post, which should have brie, tent and upto 5 tags.
   2. A user cannot create more than 1 blog post of the same title.
4. **User analysis page**
   1. This page should give the following specific scats:
      1. Last 5 recently posts created by user
      2. The %age distribution of tags of posts created by users.
      3. Top n blog posts of user by views.
      4. Distribution of tags amongst this user's posts viewership.

You don't need to worry about the login page and session tokens for now. The sleeker the analysis page, the better ;)

**Feel free to use any tech stack you want to solve this problem.**

**Brownies!**

1. (Backend) Proper caching of backend endpoints
2. (Backend) Rate limiting the endpoints.
3. (Frontend) Integrating switchable dark theme.
4. (Frontend) Displaying data in graphical format on the analysis page.

---

_I wasn't supposed to put this online but this is only for my reference._
