import setup.setup.setup.setup;

import java.util.Scanner;

public class Main extends setup {
  public static setup s = new setup() {};
  public static Scanner read_line = new Scanner(System.in);
  public static void main(String[] args) {
    System.out.print("Network Type: ");
    String net_type = read_line.nextLine();
    s.net_type(net_type);
    System.out.print("Use type for: ");
    String use_for = read_line.nextLine();
    s.use_as(use_for);
    s.is_ready();
  }
}
