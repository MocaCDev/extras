using System;

public class main {
  public static void Main() {
    String my_line = "Getting back into C#";
    bool is_getting_back = my_line == "Getting back into C#";

    if(is_getting_back)
      Console.WriteLine(my_line);
    else
      Console.WriteLine("Too bad, I'm still getting into it");
  }
}
