import java.util.*;

interface IStackOverflow {
  public void createUser();
  public void createQuestion();
}


class StackOverflow {
  
}




interface IUserService {
  public createUser(String userName, String credentials);
  public getUser(String userId)
  public updateUser(String userId);
  public deleteUser(String userId);
}


interface IQuestionsService {
  public createQuestion(String userId, String questionTitle, String questionBody, List<String> tags);

  public answerQuestion(String questionId, String questionAnswer);

  public deleteQustion(String questionId);

  public getQuestion(String questionId)
}

interface IStackOverflow {

}


@Data
class User {
  private String user_id;
  private String user_name;
  private String password; // ideally like a way to encode this 
  private Instant create_date;
}


class Response {
  String body;
  Instant create_date;
  int upVotes;
  ArrayList<Response> comments;
  String user_id;
}

class Question extends Response {
  String question_id;
  String questionTitle;
  HashSet<Strings> tags; 
}

class Answer extends Response{
  String question_id;
}

