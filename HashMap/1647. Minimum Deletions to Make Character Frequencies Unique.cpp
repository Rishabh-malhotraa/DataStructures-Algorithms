/*
 ____  _     _           _     _       __  __       _ _           _
|  _ \(_)___| |__   __ _| |__ | |__   |  \/  | __ _| | |__   ___ | |_ _ __ __ _
| |_) | / __| '_ \ / _` | '_ \| '_ \  | |\/| |/ _` | | '_ \ / _ \| __| '__/ _` |
|  _ <| \__ \ | | | (_| | |_) | | | | | |  | | (_| | | | | | (_) | |_| | | (_| |
|_| \_\_|___/_| |_|\__,_|_.__/|_| |_| |_|  |_|\__,_|_|_| |_|\___/ \__|_|  \__,_|

*/

#include <bits/stdc++.h>
using namespace std;

// EVEN the stupid approach works urghhhhh
// o(n^2)
class Solution
{
public:
  int minDeletions(string s)
  {
    int n = s.size();
    vector<int> freq(26, 0);

    for (char &ch : s)
      freq[ch - 'a']++;

    unordered_set<int> cache;
    int result = 0;
    for (int el : freq)
    {
      while (el != 0 && cache.find(el) != cache.end())
        el--, result++;
      cache.insert(el);
    }
    return result;
  }
};

// O NLOGN
class Solution
{
public:
  int minDeletions(string str)
  {
    unordered_map<char, int> freq;
    priority_queue<int> pq;
    for (char &ch : str)
      freq[ch]++;

    vector<int> counts;
    for (auto [key, value] : freq)
      counts.push_back(value);

    sort(counts.begin(), counts.end());

    int previous = 0, deletions = 0;
    pq.push(0);
    unordered_set<int> cache;
    for (int count : counts)
    {
      if (previous + 1 != count && previous != count)
      {
        pq.push(count - 1);
      }
      if (cache.find(count) == cache.end())
      {
        cache.insert(count);
      }
      else
      {
        int top = pq.empty() ? 0 : pq.top();
        pq.pop();

        while (!pq.empty() && cache.find(top) != cache.end())
        {
          top = pq.empty() ? 0 : pq.top();
          pq.pop();
        }

        deletions += count - top;
        cache.insert(top);
        int nextTop = top ? top - 1 : 0;
        pq.push(nextTop);
      }
      previous = count;
    }
    return deletions;
  }
};

/*

TEST CASES!
ckcblejibnhdgoodmgginlkljeoefnodhbabblgncndmlddamhkhlhmjgaejhogikdlcfenjkcgigafjekkickbnminlnmlckhka
vduevtfmcbzwgvycreofxlnmqwloaqkcsclyydyinftyeyniluygwrvnrdsobpurshszaytvymyvopbxdezlleqaldntagmaqqrjbpilanvgznfbeldaopsqgoyopxskcrjkeulytkdkxzjbffrgwrqxzjqvmyaahvpfbesewnxvjxtepzojesignhivikyvkhuywndupxwlntemalknjrmvmhbuicgypgdjynitefvqycmeuuikbaspippxoxseyaxlaibbfpnqjxoomgkespvctizzkclwxbczldsablgazbbqsvdahgxpvmlpbdmszqmkczucqfdcpdituqnsevfxdxdynbranvufzoqrkkyoqdadeqyxxpsgygiizcqcfleiacatjcvnecfdyduwqcendwophtricrpksfqozwbilwpfyooycajlsrmlfwdwmhhajimxpqjozuniexkmmvdehagryoljrnquumsuaybyanzwaztrrxzahiptoqlfdjrucaamhkfkqfinjasurdxyqcsjsaopfjfhmkocgvybdcibmdlzhbyijgolhlknnhlysxwqfdkhpvqnxxcpvythilfibkmbhazknnfdtimyoutqrdqskccdowbbvafhhmanodjqqznzoefrbofojjobbxqllsoyjjfucfnipqxqwbafeazepuwwrbtwffhbhvjqsjqotdjcbtxetslcdhqbamxbkncvkeyzjfxnxqqzikwdayutjtonybkzcsexqfbfygpdckyiacnfkbvdcovtqavvplohihdzsigusevhlebegkjkofitbkszwizismutbwsozzrbtzrblnhonblizdyeakahmknsiddatqvydixllgvvhmaedueeebdrhqczzrlssqjwvfmibbifpihmohgyfarwvqnsjcjpcbwldrecwasbibqfjvteweqiglmpqklhtcduoqtuixdcuwubizmjviijsperwcshsolnoofvoweholcvpcoupjyhsoudczlzismqaysoczavcxnpxgzundxzulgqebkdmnanxlblocucnrjsdmfyhutvrptgwxsbkbrivbapbjsnovarcslbvumtnxarkzkbxuhkwyuadjldifeebtfixbhdhkpauqivyfoeefecdsrbphxapvzpvrhpmkijmrhcbaalpoirtynisidciupivzkauucmyuyflngqlgkxhhopfaqmgftmsghjiasxmlidzqwvtdvdfwfsznafxwqouwuivzzximxghoyhfnlzoumazmuwmbxnpbsygapwdaaqpgrsxhvdurilwfoxfhvcvaxiwjbgibcdujfijprhmnfoejaxxxfpdkrmvbhwjduhbydgcvtgzqnnwxrnpqudcrfjvhdxhvmtkiehjdbobfctojztidxudffiividkpgybdxskvflhabnesapwsfwbygxqudqdeepuxixrgyqnsbscyvtvmmvpbywibffvdnufgiygycmzgwjgdeaeuwgwowxiwoaqlihwcfbekdlevrccmqkfbnnjfzesziheejbkwvzwumxoplkgiwxlqbxfnraodkrbzgeexffneesmmiuciasctnmyqpcvwthzcwenipcgnbtyxpcnvnivqnqcrdhcojjgbggnnewefmzofrrvpepucxtrqimdgqutdgqyaxxjjgaakiprymaudgyemdnfracvkcoqirppldnafzhjygguycypklkppyvgbhvntoyyqmbchvzankkgvmlrhdwjjozowvfkocdpfexzyqwtdqfbyhybnhalsasrzkrkfwfqfdtpjhvlyzmnechvccxvrgyumxsobxsrefwpzwlqzapahlkilbmcmiwxkfhmhjzitimclcdiizovnsovebptfixhrfehwsfdddshfosbbnbinnijxlgypjlpfpzcbqyvnfgbeypqpwmwyxyfcnxlofakynqijnifmmcnybedsbseozafjjwpyplarwfdbshsvhtwsulafffmhfjfwmzjohznkbteutwsqmuayfweiqnzccqxtwniilhutwnczalhbogtrvseexbsvrjejrxsznmhdnxghwemizjwjzdqklqlqkxhkmsvzeuycniwoeswcxsdmvppycndvnyfhanpplxuatqyulzseejkuxxbedajxmtlyuoczgoeiaqmxjathxjcekdkbskkjytmdzurmesaogvzxfoixhaqzrjujkwaijelnupuhpdqurhkckjaiyopkyhmrmaiogszygcaqavgowpcwdcjxtqmxzvwagetyiivswkowypahpxrvvgkxyxtzdiangjnztuogrwnvfduraagpcxlrtjxmgupuzpoekcqubsbetrmqzqjljkjeknpnrqjnnrfbynnzgwcezqlduwspnudxxdibovigfyssfcymwzgkzfygmshdzyokdurtrtdtyzqkbhljrepwacshrphfklckhhkwcwzwelnnfyokgrypiydoecmlvektdmffobdyafepkvudhjksijdcibzpvzybferltimneopbybshwucnmrmbxhavqxinzqwvfqpnwnbyybiblvzbiqyueqfgejezxwwdzsqspjomzuyxuyhidqezxyjkflrplkqqsmncwnkvhfiajxxgpkoufqleltyhatndekarzubvjjouqqxarhniyswdpnvhowugadpxrnurvaowyzogbphpuotgzuhutlsjbttgsimpasnbzqhmmgjczdpqmyepwfsyexepkokptqaukijqomaqibbhteavrhjuduvryabwklfzuctdbzhfvtxfmdzxffohxbrkaxnmaorbeprjofrkiqefnqxwunynavpggeqxielnvyniafqptuptpiswmihpablvlxztqcostiyngvaogjdrvgccjtphenvsyehznyqymebbvzxqxbimlzyrlazvwadauanwrznltzuybhybnthuozgpledgmyunglprgkahpxdmqsncjdfnkqpjtwljwosvrgzhketjwaatwmvttrkhzayohpmmndggtkfqhskmfwcbzpogwaqffyterrvndxtehxlhuvkwcthksirvnjsnxwqhgllestawrpayjggxasaraytrewaeoqldqsxufgplcuqsuthdzzhrjoznltmdatjcungcexrsexxiermikjrthcnhdwnzcuhhggyfzolbljuslrbtmgcsdkkxorflakvqeskbdcrgsthomygxobtvpyixigismoqmxictyevznpvzikheeojwwohwubjkhjvwsdohnifthhrrzexzxobkndrcohjztvatespwcnbhjxlhkjgizeycrilxuvwbwthylevooixqyugeirfbkuebjomdvfeqhkuskjpywnfjbnmiaiojmpleqhkskryidbgolfleqakdvmlcqyzuqyqatkqjhhjprwzkwurkuaqmzwppjayqylciamtkvrujgrfbmbfvukfyvcnavulfemiyyvyggpvxxplwdxzizexrpwraliaogvmqvbjkorwhigqklrfpfteecyqlemzafamhtvfmhhkzocifonlqwqycpybteusjibiqdbkzbniwqkhzpcvwoaxqkrudbzzlkvmnweadgdlpngplddjdvowakipkknzfnqdtqtipymuryrwjwhlujptaoryvoqseidllnwbavbcozcfqjwackdfrclzzzuclzgqajghaidvrfggooigxynrijyqibcxfadytzrcfrfqdfjpjirridcltazdomvsuqjuutexidhecmysahljyadfpxsiftccumvxtmuthwrzfjemmonrpdrzmrxrrhkxzmytxjwmefgqfrtmurtqbtcmewdzelavfantqznimmmvrbkojxyoqcmenklwksmzqcazgljktncnbxrrzpiibqnzvngibgjyhldeowsfhwmtpmrpjiyamkdxwyuothcpgfzakorakqkrfsvhfiixytxigvomiliisrvomuwtfgzniiyxkbdfhafjehsovziwrhdkkopdtuhgazdryyfmkbvapaqjvbzqpzgcuqqhsivmpifvoeblkjgghmdpjaxiammdvgmaodsiwauahraeeydcrzdwtlrjkrjopyoojurgohnrblohseysopjuxexbvzubsyvqzbxwuvfnoucnhdwfdjiiuxwzzjagnhskektdkwuksuccwjblvsinkdvapkgmyshvlcjuedwbybsdsmlekjpcuwplxrhpxllavtdjvmunfuuovefetgypzhkmjgneywzzmkjawlwaaxgenacbpwbrlikefsqfqlqynbwglcmagxgszachrpqetkobijnhouoepdapavofmozvoaknpkvfenyapnchdbtxqjfcbqcivozajkxnfvophhhrzvbrqcjooqwupsdscsqanghtvhnwepaitqsqzaoalzmurxygccgotrltdimwczaaziqljojwbctnemnemiktpykmkinoluijvbdoejwmauuzecwicmnwamykmgkfsjmnjxoynepntluvtnoqrunjdjxrnuoesodsjohphuayyntyrbbhgqaxauozrimepakbbztygfwhudazlgoicdcixmpxceccwsdrwtlveyyrhthyzpzzybmdjpkeffnkuyjyeqphocilcyqcyhndfdkmbkfxzkinovgeufloyaddzyqxhmlyokhjwyducpsyrhszpymhvuqzcqqedodvkrugricicmrukmqtaptgoqzvmckhldxzmwljpcgsgsindtsrdhfrnctbdwjsfquhxvnpwyfyehnqjwufuexcjjaocvrxvtygvxoyoqfjfikaygvdgpfczylsjxgycgbdgzdzsqtkbienvzecnztislrejvprcecysinialidfwnplulmtgsxfmqcdofwynjslnaxxqofihpdowwuarnkaarbaremrupzzwpmqjnsppinayiuupttknhiuxmncgocgzgdvpfgpacraeduibcnrllvhfinaonfpkfjjdsdsaeddhzedqtexvgziyopwdvxlnzhqqdltazpisegpnbgxzegaluwxutpifsbeerjrtjnbgtcaujnzzupfjwkcycwymdyjnsbjsanzmgiwsfflmgrhuskjzytvpoclosesitxggtedydccxclxulmcejjecccrovpqihaqyyoczxlpzzshdfueoffxjqtcfijeqmcaymnhdshjlkzriqanfrdejdmtuhstuheftmrrfevjmaxbkpvorapjdbxdndqnwhqgjwahboccuwfvuoiwjyvqjosrqhpcrhfdbtrklbsrsxiueqhxnzwbuhalofvyabwxkqpeyyhzdkcfykyicundgatzmuoqzbkkbnkdznqtczilmwpdnsoayzcxplatroafsprgqrwmulhtmnyupyxuczhbxysylhtzimdfvvgfoiwzakrslwuvvixlhunmnigjxqpdvufprcxmpuvzwazmmswvvtgchrlzourkdhpitzditluiitkypqhxmcrznapbgqmbjqcrnizpkdbeovxmwfnbyezmxsfobjxvkvbhagbwtdbdowricsnrkfzawbkxsofugewnhznwohgeftphbbghporwisdslqceqvwssjcomoancmidphevvtmiubblqzotfmcjgumqoewzylyygsgttyphkdxwkcbznjtxoasiobrdzabpxcedykvxaqkozdubvttubxmgypxwbihbiyfgxcvtuyhehetaslpiszsvjdojsouvfqbpemoxvxowijlrrbavnaernlibxxrfasqmlvpekkgcicxbqaaunijqauloqkffdeeklkegqbnarugjjgkunnsrmgsivonqidedxtuywmcrfwwunszzucswrtlkhfngxarzaiqmktkutnukqoiwcxvveeahiqplvyiiuegbfbbtrghdnknpyhtgcezholgeyosgrtlesxmnytindqpeoikssqbjphoilanyalydfczoupnzoljjidwzmuzpzfzxkfzhtqbgewfrajqtlmyelrywohiqtxfakysiflpiapedzeuwhdgisgfwkcqpcsyarylkfdwpuhzszrveskakztkpsxdyiovtrcwlqgqdmewqyfotfhneifzgdkxzruaoneqojfqsrksgdgtppehxpzfypgmnfldbwkisguzxbmjltihuspksbzhhveluvokkzxxtlvhgyxjcwkekyekgnyfudareewokvmqtsztjbxwtzfpmgopaudrhsomtnzvfhpffixqcgsmulpyvurijzqqixixjoyzcurpzstjhhyogetcxtuojxzzlfbbmfymcfufewjivlawinlaviiindtqtcyvzxssrbvwlrzyjkcomgdkixgdokvxgfblrbcjeahizbnxsojyquaffxvzvlrxluaplbeteuzrpfujmyrlulgvabqbhchwjwsxgkyfomnncnwurwxvuqjvzndeytsckiiqncjihgewzbrvdjbqtpwnmgivptjixdeqwkrlazrbtcytjwgcxxnpaukyahgvxxrepaqkohjccneyfftuekicnlookxegqmaijsqexulcnndkecuxsrydztozblxrtwikastjfkcrzwydfqssxksntneltocjtbagrxffekdanxryrrdbmivenievehrmavwilzimbedamcfiawshqwuglmcbwbbcvzqnnfnasajapbxlmwfmzkwbwelutttmkkqdhjdgxixdfzspnzvxrqwzojydjyutffwmxgrqcjzunhooqzqeplwbtcragbugzxfctkfkgdukvqebsefgamfnxhfohscvnyivjncfqdlfpxztnpslzalmcqxyvzntvlihalrguzoqtjzjwxofxfwphefaxxglfiwliextmiakdltuglofhyvevmajndwuivndyjigcmqdelelnmrmkapnxlggtcgttkwhlyyhlwookqgvnfokqingihljvbjhtaeyaovpgsflzjzjurcqrftcsifldawynmtzbvhqfyvopcqxskqguxiuqfvvlfhjhvirscxtkegijprqjmtnccqfrcddtlmjenoyjvyrqckxibicvdstuuwcheroknrjhkivgsfcjemrmkxzxkmpeizpmupblhvjmwuoueenniuykkdjpvwwubbcflswldjlxopolyrclihcoduvqctwrkbzqkbrgzigjcfuukektblwvtddpubmrsitycmzjeljsygkqrpsyrquftpatvnfmlhlpxxjirmasvklqtlucblzpujqogjilmoxhsthnhepphjrvrxdbpvobhrvzexffvuevutqqsrzldyeblxelwresuqurgasanbodmqfasnkwqlvwqsubjnpjkwxmxmfhwjocxsoorbrxiziaowyzjrapgcrhvcjruemimgulvroqpkafocxgajhqcxbjdtmrylpqkzsqlmsryjrngcksbuhtzgweasdsmrmxuhebpuboxryxcnkqllrriurdzoqawkjmzsdcaikmfgtwnjnjlpnimobklxrmyobphyvcupxhknyshczywlwnbjybckmjcvjagvbykohribodpbkmoaabyfyewjmhhqlilbudehuqtpiuzcuijjzcdsblsnwpfqempswofysrcjrhcuprmoggpkelhnkpplflmmkpzwt

*/