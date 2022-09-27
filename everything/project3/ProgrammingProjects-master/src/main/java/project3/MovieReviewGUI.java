package project3;

import java.awt.Color;
import java.awt.Component;
import java.io.IOException;
import java.util.List;
import java.util.Scanner;
import javax.swing.*;
import java.awt.event.*;
/**
 * Main application class. Creates a GUI for Movie Review program.
 * @author Cole Hurst
 */

class MovieReviewGUI {
    
    static final Scanner CONSOLE_INPUT = new Scanner(System.in);
    JFrame r;
    JTextField t;
    JButton b0, b1, b2, b3;
    JOptionPane o1;
    JPanel p;
    JScrollPane s;
    
    static int operator = 0;    

    
    /**
     * This is the GUI constructor class and establishes all the tools to get the 
     * program to run smoothly
     * 
     * @param rh
     */
    MovieReviewGUI(ReviewHandler rh){
        
        r = new JFrame("Movie Review Menu");
        p = new JPanel();
        t = new JTextField("Database size: " + rh.getDatabase().size());
        b0 = new JButton ("0. Exit program.");
        b1 = new JButton ("1. Load new movie review collection (given a folder or a file path).");
        b2 = new JButton ("2. Delete movie review from database (given its id).");
        b3 = new JButton ("3. Search movie reviews in database by id or by matching a substring.");
        s = new JScrollPane(p);
        
        
        /**
         * Adjusting all the buttons to make them feel native to the JFrame
         * giving unique colors to associated arguments
         */
        b0.setBounds(40, 30, 500, 30);
        b1.setBounds(40, 70, 500, 30);
        b2.setBounds(40, 110, 500, 30);
        b3.setBounds(40, 150, 500, 30);
        t.setBounds(40, 230, 500, 60);
        
        r.setLayout(null);
        r.setVisible(true);
        r.setSize(600, 400);
        r.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        r.setResizable(false);
        r.setBackground(Color.GREEN);
        r.setForeground(Color.GREEN);
        b0.setBackground(Color.RED);
        b1.setBackground(Color.GREEN);
        b2.setBackground(Color.GREEN);
        b3.setBackground(Color.GREEN);
        
        r.add(t);
        r.add(b0);
        r.add(b1);
        r.add(b2);
        r.add(b3);
        
        /**
         * Creates an action lister while also directly calling its action performer.
         * performing the action of closing the program
         * 
         */
        
        b0.addActionListener(new ActionListener(){
        public void actionPerformed(ActionEvent e){
            System.exit(0);
        }
        });
        
        /**
         * Creates an action lister while also directly calling its action performer.
         * creates a dialogue box in which the user enters the direct adress of 
         * reviews they would like to enter.
         * Then follows up with a classifying "real class"
         * that is declared within the function
         * Stores both reviews and real class to the data base.         * 
         */
        b1.addActionListener(new ActionListener(){
        public void actionPerformed(ActionEvent e){
            t.setText("");
            String path = JOptionPane.showInputDialog("Please input the path of file or folder: ");        
            
            int realClass = Integer.parseInt(JOptionPane.showInputDialog("Please input real class (0, 1, 2). \n 0 = negative, 1 = positive, 2 = unknown."));
            
            if (realClass >= 0 && realClass <= 2) {
                 rh.loadReviews(path, realClass);
                 t.setText(t.getText().concat("Database size: " + rh.getDatabase().size()));
             } 
            else {
                 t.setText(t.getText().concat("Illegal Input"));   
             }
            
            
        }
        });
        
        /**
         * Creates an action lister while also directly calling its action performer.
         * Creates a dialogue box that inputs an integer from the user,
         * then uses that integer to identify the review number to be deleted.         * 
         */
        b2.addActionListener(new ActionListener(){
        public void actionPerformed(ActionEvent e){
            
            t.setText("");
            
            String idStr = JOptionPane.showInputDialog("Please input review ID: ");
            
            if (!idStr.matches("-?(0|[1-9]\\d*)")) {
                        // Input is not an integer
                        t.setText("Illegal Input");
                    } else {
                        int id = Integer.parseInt(idStr);
                        rh.deleteReview(id);
                    }
        }
        });
        
        b3.addActionListener(new ActionListener(){
        public void actionPerformed(ActionEvent e){
            t.setText("");
            String substring = JOptionPane.showInputDialog("Please input substring:");
            List<MovieReview> reviewList = rh.searchBySubstring(substring);
            if (reviewList != null){
                for(MovieReview mr : reviewList){
                    
                }
            }
            
        }
        });
    }

        /** 
        *This is the main that just loads and saves the database, creates reviewhandler
        * and calls the GUI constructor.
        * 
        *@param args 
        */
    public static void main(String[] args) {
                
        if (args.length < 2) {
            System.err.println("Please provide command liner arguments: <posFilePath> and <negFilePath>");
            Component frame = null;
            JOptionPane.showMessageDialog(frame, "Please provide command liner arguments: <posFilePath> and <negFilePath>");
            return;
        }
        
        else   {
            String pathToPosWords = args[0];
            String pathToNegWords = args[1];
        }
            
        ReviewHandler rh = new ReviewHandler();
            
        try {
            // Load database if it exists.
            rh.loadDB();
        } catch (IOException ex) {
            System.err.println("Error accessing the database file.");
            return;
        }
        
         
        new MovieReviewGUI(rh);
        
        try {
            // Save the database before exiting.
            rh.saveDB();
        } catch (IOException ex) {
            System.err.println("Error: The database file could not be saved.");
        }
                
        System.out.println("See you!");
        System.out.println("See you!");
            
    }
    
    public static void printTableHead() {
        String line = "------------------------------------------------------------------------------------------";
        String information = "| ";
        information = information + String.format("%4s", "ID") + " | ";
        information = information + String.format("%53s", "Text") + " | ";
        information = information + String.format("%10s", "Predicted") + " | ";
        information = information + String.format("%10s", "Real") + " |";

        System.out.println(line);
        System.out.println(information);
        System.out.println(line);
    }
    
    public static void printTableContent(MovieReview mr) {
        String line = "------------------------------------------------------------------------------------------";
        String information = "| ";
        information = information + String.format("%4s", mr.getId()) + " | ";
        information = information + String.format("%53s", mr.getText().substring(0, 50)+"..." ) + " | ";
        information = information + String.format("%10s", mr.getPredictedScore()) + " | ";
        information = information + String.format("%10s", mr.getPredictedScore()) + " |";

        System.out.println(information);
        System.out.println(line);
    }

}
