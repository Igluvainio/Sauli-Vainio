import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class AjastinDemo extends JFrame implements ActionListener {
    private JTextField sekuntiKentta;
    private JButton aloitaNappi;
    private Timer ajastin;
    private int sekunnit;

    public AjastinDemo() {
        setTitle("Sekunttilaskin");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(300, 100);
        setLayout(new FlowLayout());

        sekuntiKentta = new JTextField(5);
        aloitaNappi = new JButton("Aloita ajastin");
        aloitaNappi.addActionListener(this);

        add(new JLabel("Sekuntimäärä:"));
        add(sekuntiKentta);
        add(aloitaNappi);

        ajastin = new Timer(1000, this);
        ajastin.setInitialDelay(0);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == aloitaNappi) {
            String sekuntiTeksti = sekuntiKentta.getText();
             try {
                sekunnit = Integer.parseInt(sekuntiTeksti);
                ajastin.start();
                aloitaNappi.setEnabled(false);
                sekuntiKentta.setEnabled(false);
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(this, "Virheellinen syöte! Syötä kokonaisluku sekuntimäärälle.");
            }
        } else if (e.getSource() == ajastin) {
            if (sekunnit > 0) {
                System.out.println(sekunnit + " sekuntia jäljellä.");
                sekunnit--;
            } else {
                System.out.println("Ajastin pysäytetty.");
                ajastin.stop();
                aloitaNappi.setEnabled(true);
                sekuntiKentta.setEnabled(true);
            }
        }
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new AjastinDemo().setVisible(true);
            }
        });
    }
}

