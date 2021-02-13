import java.util.Scanner;
import java.lang.Runtime;
import java.awt.*;
import javax.swing.*;

public class os_name{

        private static Scanner user_input = new Scanner(System.in);

        private static String gatherOsName (boolean print){

                String os_name = System.getProperty("os.name");
                if(print == true)
                {
                        System.out.println(os_name);
                        System.out.flush();
                        try {
                                JFrame frame = new JFrame();
                                JButton button = new JButton("something");
                                frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                                frame.getContentPane().add(button);
                                frame.setSize(200,200);
                                frame.setVisible(true);
                                button.setText("I was pressed!");
                        } catch(Exception e)
                        {
                                System.out.println("There was an error: "+e);
                                System.exit(1); // error
                        }
                }
                return os_name;
        }

        public static void main(String[] args) {
                System.out.print("Do you want to print the os name?[y/n] > ");
                String y_o_n = user_input.next();
                if(y_o_n.equals("y"))gatherOsName(true);
                else gatherOsName(false);
                System.out.println("Hello, world");
        }

}
