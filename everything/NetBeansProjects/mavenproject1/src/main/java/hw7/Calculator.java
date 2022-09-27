package hw7;

import javax.swing.*;
import java.awt.event.*;
import static java.lang.Math.sqrt;
import java.awt.Color;

/**
 * Add javadoc to the file
 */
class Calculator implements ActionListener {

    JFrame f;
    JTextField t;
    JButton b1, b2, b3, b4, b5, b6, b7, b8, b9, b0, bdiv, bmul, bsub, badd, bdec, beq, bdel, bclr, bovr, bsqr, bsrt;

    static double a = 0, b = 0, result = 0;
    static int operator = 0;

    Calculator() {
        f = new JFrame("Calculator");
        t = new JTextField();
        b1 = new JButton("1");
        b2 = new JButton("2");
        b3 = new JButton("3");
        b4 = new JButton("4");
        b5 = new JButton("5");
        b6 = new JButton("6");
        b7 = new JButton("7");
        b8 = new JButton("8");
        b9 = new JButton("9");
        b0 = new JButton("0");
        bdiv = new JButton("/");
        bmul = new JButton("*");
        bsub = new JButton("-");
        badd = new JButton("+");
        bdec = new JButton(".");
        beq = new JButton("=");
        bdel = new JButton("Del");
        bclr = new JButton("Clear");
        bovr = new JButton("1/x");
        bsqr = new JButton("x^2");
        bsrt = new JButton("√x");

        /**
        * using .setbounds to individually create each button's
        * set dimensions, resizing each to fit the extra buttons 
        * added for this assignment
        */
        
        t.setBounds(50, 40, 280, 30);
        b7.setBounds(20, 100, 60, 40);
        b8.setBounds(80, 100, 60, 40);
        b9.setBounds(140, 100, 60, 40);
        bdiv.setBounds(240, 100, 60, 40);
        bovr.setBounds(300, 310, 60, 40);

        b4.setBounds(20, 170, 60, 40);
        b5.setBounds(80, 170, 60, 40);
        b6.setBounds(140, 170, 60, 40);
        bmul.setBounds(240, 170, 60, 40);
        bsqr.setBounds(300, 170, 60, 40);

        b1.setBounds(20, 240, 60, 40);
        b2.setBounds(80, 240, 60, 40);
        b3.setBounds(140, 240, 60, 40);
        bsub.setBounds(240, 240, 60, 40);
        bsrt.setBounds(300, 240, 60, 40);

        bdec.setBounds(20, 310, 60, 40);
        b0.setBounds(80, 310, 60, 40);
        beq.setBounds(140, 310, 60, 40);
        badd.setBounds(240, 310, 60, 40);

        bdel.setBounds( 300, 100 , 60, 40);
        bclr.setBounds(100, 380, 200, 40);
        
        /**
        * Actually adding the buttons to the calculator frame.
        */
        f.add(t);
        f.add(b7);
        f.add(b8);
        f.add(b9);
        f.add(bdiv);
        f.add(bovr);
        f.add(b4);
        f.add(b5);
        f.add(b6);
        f.add(bmul);
        f.add(bsqr);
        f.add(b1);
        f.add(b2);
        f.add(b3);
        f.add(bsub);
        f.add(bsrt);
        f.add(bdec);
        f.add(b0);
        f.add(beq);
        f.add(badd);
        f.add(bdel);
        f.add(bclr);
           
        /**
        * Settings for the calculator function. size, color, and how the 
        * calc functions when exited are created here.
        */
        
        f.setLayout(null);
        f.setVisible(true);
        f.setSize(400, 500);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setResizable(false);
        f.setBackground(Color.BLUE);
            
        /**
        * Action listeners that wait for the user to input a command, each for 
        * an individual process of the calculator.
        */
        
        b1.addActionListener(new ActionListener(){
        public void actionPerformed(ActionEvent e){
            t.setText(t.getText().concat("1"));
        }
        });
        
        b2.addActionListener(new ActionListener(){
        public void actionPerformed(ActionEvent e){
            t.setText(t.getText().concat("2"));
        }
        });
        
        b3.addActionListener(new ActionListener(){
        public void actionPerformed(ActionEvent e){
            t.setText(t.getText().concat("3"));
        }
        });
        
        b4.addActionListener(new ActionListener(){
        public void actionPerformed(ActionEvent e){
            t.setText(t.getText().concat("4"));
        }
        });
        
        b5.addActionListener(new ActionListener(){
        public void actionPerformed(ActionEvent e){
            t.setText(t.getText().concat("5"));
        }
        });
        
        b6.addActionListener(new ActionListener(){
        public void actionPerformed(ActionEvent e){
            t.setText(t.getText().concat("6"));
        }
        });
        
        b7.addActionListener(new ActionListener(){
        public void actionPerformed(ActionEvent e){
            t.setText(t.getText().concat("7"));
        }
        });
        
        b8.addActionListener(new ActionListener(){
        public void actionPerformed(ActionEvent e){
            t.setText(t.getText().concat("8"));
        }
        });
        
        b9.addActionListener(new ActionListener(){
        public void actionPerformed(ActionEvent e){
            t.setText(t.getText().concat("9"));
        }
        });
        
        b0.addActionListener(new ActionListener(){
        public void actionPerformed(ActionEvent e){
            t.setText(t.getText().concat("0"));
        }
        });
        
        bdec.addActionListener(new ActionListener(){
        public void actionPerformed(ActionEvent e){
            t.setText(t.getText().concat("."));
        }
        });
        
        badd.addActionListener(new ActionListener(){
        public void actionPerformed(ActionEvent e){
            a = Double.parseDouble(t.getText());
            operator = 1;
            t.setText("");
        }
        });
        
        bsub.addActionListener(new ActionListener(){
        public void actionPerformed(ActionEvent e){
            a = Double.parseDouble(t.getText());
            operator = 2;
            t.setText("");
        }
        });
        
        bmul.addActionListener(new ActionListener(){
        public void actionPerformed(ActionEvent e){
            a = Double.parseDouble(t.getText());
            operator = 3;
            t.setText("");
        }
        });
        
        bdiv.addActionListener(new ActionListener(){
        public void actionPerformed(ActionEvent e){
            a = Double.parseDouble(t.getText());
            operator = 4;
            t.setText("");
        }
        });
        
        bovr.addActionListener(new ActionListener(){
        public void actionPerformed(ActionEvent e){
            a = Double.parseDouble(t.getText());
            operator = 5;
            t.setText("");
        }
        });
        bsqr.addActionListener(new ActionListener(){
        public void actionPerformed(ActionEvent e){
            a = Double.parseDouble(t.getText());
            operator = 6;
            t.setText("");
        }
        });
        bsrt.addActionListener(new ActionListener(){
        public void actionPerformed(ActionEvent e){
            a = Double.parseDouble(t.getText());
            operator = 7;
            t.setText("");
        }
        });

        
        beq.addActionListener(new ActionListener(){
        public void actionPerformed(ActionEvent e){
            b = Double.parseDouble(t.getText());

            switch (operator) {
                case 1:
                    result = a + b;
                    break;

                case 2:
                    result = a - b;
                    break;

                case 3:
                    result = a * b;
                    break;

                case 4:
                    result = a / b;
                    break;
                
                case 5:
                    b = 0;
                    result = 1 / a;
                    break;
                  
                case 6:
                    b = 0;
                    result = a * a;
                    break;
                 
                case 7:
                    b = 0;
                    result =  sqrt(a);
                    break;

                default:
                    result = 0;
            }

            t.setText("" + result);
        }
        });
             
        bdel.addActionListener(new ActionListener(){
        public void actionPerformed(ActionEvent e){
            String s = t.getText();
            t.setText("");
            for (int i = 0; i < s.length() - 1; i++) {
                t.setText(t.getText() + s.charAt(i));
            }
        }
        });
        
        bclr.addActionListener(new ActionListener(){
        public void actionPerformed(ActionEvent e){
            t.setText("");
        }
        });
        
        
       
    }

    public static void main(String[] args) {
        Calculator calculator = new Calculator();
    }
}
