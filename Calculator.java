import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Calculator {

    private JFrame frame;
    private JTextField textFieldNum1;
    private JTextField textFieldNum2;
    private JTextField textFieldResult;

    public Calculator() {
        // Frame 
        frame = new JFrame("Calculator");
        frame.setSize(300, 200);
        frame.setLayout(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Text fields
        textFieldNum1 = new JTextField();
        textFieldNum1.setBounds(20, 20, 100, 25);
        frame.add(textFieldNum1);

        textFieldNum2 = new JTextField();
        textFieldNum2.setBounds(140, 20, 100, 25);
        frame.add(textFieldNum2);

        textFieldResult = new JTextField();
        textFieldResult.setBounds(20, 60, 220, 25);
        textFieldResult.setEditable(false); // Make it read-only
        frame.add(textFieldResult);

        // Buttons
        JButton addButton = new JButton("Add");
        addButton.setBounds(20, 100, 60, 25);
        addButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                performOperation('+');
            }
        });
        frame.add(addButton);

        JButton subtractButton = new JButton("Subtract");
        subtractButton.setBounds(90, 100, 90, 25);
        subtractButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                performOperation('-');
            }
        });
        frame.add(subtractButton);

        JButton multiplyButton = new JButton("Multiply");
        multiplyButton.setBounds(190, 100, 90, 25);
        multiplyButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                performOperation('*');
            }
        });
        frame.add(multiplyButton);

        JButton divideButton = new JButton("Divide");
        divideButton.setBounds(120, 140, 90, 25);
        divideButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                performOperation('/');
            }
        });
        frame.add(divideButton);

        frame.setVisible(true);
    }

    private void performOperation(char operator) {
        try {
            double num1 = Double.parseDouble(textFieldNum1.getText());
            double num2 = Double.parseDouble(textFieldNum2.getText());
            double result = 0;

            switch (operator) {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    if (num2 != 0) {
                        result = num1 / num2;
                    } else {
                        throw new ArithmeticException("Cannot divide by zero.");
                    }
                    break;
                default:
                    throw new IllegalArgumentException("Invalid operator: " + operator);
            }

            textFieldResult.setText(String.valueOf(result));
        } catch (NumberFormatException e) {
            textFieldResult.setText("Invalid input");
        } catch (ArithmeticException e) {
            textFieldResult.setText(e.getMessage());
        } catch (IllegalArgumentException e) {
            textFieldResult.setText(e.getMessage());
        }
    }

    public static void main(String[] args) {
        new Calculator();
    }
}
