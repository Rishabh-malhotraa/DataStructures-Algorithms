struct Node {
  string name;
  vector<Node*> directReports;
};

string getCommanManager(string employee, string employee1, string employee2,
  unordered_map<string, vector<string>> companyHierarchy) {
  if (employee == employee1 || employee == employee2) {
    return employee;
  }

  stack<string> managerFound;
  for (string directReport : companyHierarchy[employee]) {
    string searchResult =
      getCommanManager(directReport, employee1, employee2, companyHierarchy);
    if (searchResult != "")
      managerFound.push(searchResult);
  }

  if (managerFound.size() == 2) {
    return employee;
  }
  else if (managerFound.size() == 1) {
    return managerFound.top();
  }
  else {
    return "";
  }
}

Node* getCommonManager(Node* node, string employee1, string employee2) {
  if (node == NULL) {
    return NULL;
  }

  if (node->name == employee1 || node->name == employee2) {
    return node;
  }

  vector<Node*> matches;
  for (Node* directReport : node->directReports) {
    Node* tempAns = getCommonManager(directReport, employee1, employee2);
    if (tempAns != NULL) {
      matches.push_back(tempAns);
    }
  }

  if (matches.size() == 2)
    return node;
  else if (matches.size() == 1)
    return matches[0];
  else
    return NULL;
}