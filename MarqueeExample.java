import javax.swing.JFrame;
import javax.swing.JLabel;

public class MarqueeExample extends JFrame{
    private String text = "Hello java";
    private JLabel label= new JLabel();
    private int x =0 ,y=0 ;

    public MarqueeExample(){
        this.setTitle("Marquee");
        label.setLocation(x, y);
        label.setText(text);
        this.add(label);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(600,400);
        setVisible(true);
        startMarquee();
    }



    static class RunTask implements Runnable{
        private int x,y,maxWidth;
        private JLabel label;

        public RunTask(int x, int y, int maxWidth, JLabel label){
            this.x=x;
            this.y=y;
            this.maxWidth =maxWidth;
            this.label = label;
        }

        @Override
        public void run(){
            while (true) {
                x+=5;
                if (x>maxWidth){
                    x=0;
                }
                label.setLocation(x,y);
                try{
                    Thread.sleep(100);
                }catch(InterruptedException e){
                    e.printStackTrace();
                }   
            }
        }
    }

    private void startMarquee (){
        RunTask rt = new RunTask(x, y, getWidth(), label);
        Thread marqueeThread = new Thread(rt);
        marqueeThread.start();

    }

    public static void main(String[] args) {
        MarqueeExample marqueeExample = new MarqueeExample();
        
    }
}