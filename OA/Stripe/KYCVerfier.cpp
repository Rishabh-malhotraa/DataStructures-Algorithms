#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;

class KYCVerfier {
public:

  KYCVerfier(string rawInput, vector<string> genericStatements) {
    this->genericStatements = genericStatements;
    split(fields, rawInput, boost::is_any_of("\n"));
    split(requiredFields, fields[0], boost::is_any_of(","));
    rawInputs = vector<string>(fields.begin() + 1, fields.end());
  }

  vector<string> generateReport() {
    vector<string> report;
    for (string rawInput : rawInputs) {
      auto [companyName, isVerfied] = isCompanyVerified(rawInput);

      string status = (isVerfied ? "VERIFIED: \t" : "NOT VERFIED: \t") + companyName;
      report.push_back(status);
    }

    return report;
  }

private:
  vector<string> requiredFields;
  vector<string> genericStatements;
  vector<string> fields;
  vector<string> rawInputs;
  pair<string, bool> isCompanyVerified(string rawString) {
    vector<string> fields;
    split(fields, rawString, is_any_of(","));
    unordered_map<string, string> companyDetails;

    bool allFieldsPresnet = true;

    for (int i = 0; i < (int)requiredFields.size(); i++) {
      if (fields[i].empty())
        allFieldsPresnet = false;
      companyDetails[requiredFields[i]] = fields[i];
    }

    bool isFullNameDescritorValid = validateDescription(companyDetails["full_statement_descriptor"]);

    bool containsGenericWords = checkForGenericWord(companyDetails["full_statement_descriptor"]);

    bool verified = allFieldsPresnet && isFullNameDescritorValid && !containsGenericWords;

    return { companyDetails["business_name"], verified };
  }

  bool checkForGenericWord(string description) {
    for (string statement : genericStatements) {
      bool doesContain = boost::contains(description, statement);
      if (doesContain)
        return true;
    }
    return false;
  }

  bool validateDescription(string description) {
    int n = description.size();
    if (n >= 5 && n <= 31)
      return true;
    return false;
  }
};

int main() {
  vector<string> genericStatements{ "ONLINE STORE","ECOMMERCE","RETAIL","SHOP", "GENERAL MERCHANDISE" };

  string rawInput = "product_description,full_statement_descriptor,short_statement_descriptor,business_name,business_profile_name,url\nOnline pet supplies,FURRY FRIENDS EMPORIUM,FURRYFRIEND,Pawsome Pets Inc.,Furry Friends Emporium,https://furryfriendsemporium.com\nArtisanal coffee roaster,BEAN BLISS COFFEE CO,,Bean Bliss Coffee Company,Bean Bliss Coffee,https://beanblisscoffee.com\nHandcrafted furniture,OAKRIDGE CUSTOM WOODWORKING AND FURNITURE EMPORIUM,OAKRIDGEFURN,Oakridge Furniture Crafters LLC,Oakridge Custom Woodworking,https://oakridgecustomfurniture.com\nYoga studio,OMYOGA,OM,Om Yoga and Wellness Center,Om Yoga,https://omyogacenter.com\nIT consulting services,ITCS,ITC,Information Technology Consulting Solutions Inc.,ITCS,https://itconsultingsolutions.com\nOnline retail store,ONLINE STORE,ONLINESTR,Global Goods Marketplace Inc.,Global Goods,https://globalgoodsmarket.com\nDigital marketing agency,APEX ONLINE SOLUTIONS,APEXONLINE,Evergreen Digital Strategies LLC,Evergreen Digital,https://evergreendigital.com\nGourmet ice cream shop,SWEET DREAMS ICE CREAM,SWEETDREAM,Sweet Dreams Creamery LLC,Sweet Dreams Ice Cream Parlor,https://sweetdreamscream.com\nFinancial advisory services,GFAS,GF,Global Financial Advisory Services Inc.,Global Financial,https://globalfinancialadvisory.com\nTech consulting,NIS,NIS,Northwest Innovation Technologies Corporation,Northwest IT Solutions,https://northwestinnovation.tech";

  KYCVerfier verfier(rawInput, genericStatements);

  vector<string> report = verfier.generateReport();

  for (string page : report) {
    cout << page << endl;
  }

  return 0;
}

/*

Approach


So ill process string-> tokenize them using split operation

fill them up in hashmap -> hashmap[key] = value



vector<string> requiredFieds = {}


VERIFIED:      Pawsome Pets Inc.
NOT VERIFIED:  Bean Bliss Coffee Company
VERIFIED:      Oakridge Furniture Crafters LLC
VERIFIED:      Om Yoga and Wellness Center
VERIFIED:      Information Technology Consulting Solutions Inc.
VERIFIED:      Global Goods Marketplace Inc.
VERIFIED:      Evergreen Digital Strategies LLC
VERIFIED:      Sweet Dreams Creamery LLC
VERIFIED:      Global Financial Advisory Services Inc.
VERIFIED:      Northwest Innovation Technologies Corporation


VERIFIED:      Pawsome Pets Inc.
NOT VERIFIED:  Bean Bliss Coffee Company
NOT VERIFIED:  Oakridge Furniture Crafters LLC
VERIFIED:      Om Yoga and Wellness Center
NOT VERIFIED:  Information Technology Consulting Solutions Inc.
VERIFIED:      Global Goods Marketplace Inc.
VERIFIED:      Evergreen Digital Strategies LLC
VERIFIED:      Sweet Dreams Creamery LLC
NOT VERIFIED:  Global Financial Advisory Services Inc.
NOT VERIFIED:  Northwest Innovation Technologies Corporation



VERIFIED:      Pawsome Pets Inc.
NOT VERIFIED:  Bean Bliss Coffee Company
NOT VERIFIED:  Oakridge Furniture Crafters LLC
VERIFIED:      Om Yoga and Wellness Center
NOT VERIFIED:  Information Technology Consulting Solutions Inc.
NOT VERIFIED:  Global Goods Marketplace Inc.
VERIFIED:      Evergreen Digital Strategies LLC
VERIFIED:      Sweet Dreams Creamery LLC
NOT VERIFIED:  Global Financial Advisory Services Inc.
NOT VERIFIED:  Northwest Innovation Technologies Corporation
*?







using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

