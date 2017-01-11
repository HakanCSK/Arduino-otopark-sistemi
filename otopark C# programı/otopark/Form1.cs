using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Timers;
namespace otopark
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            timer1.Enabled = true;
            timer1.Interval = 100;
        }

        private void panel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (!serialPort1.IsOpen)
                serialPort1.Open();
            string sonuc = serialPort1.ReadLine();
            sonuc = sonuc.Trim();
            if (sonuc == "cikisac")
            {
                panel3.Visible = false;
            }
            if (sonuc == "cikiskapat") {
                panel3.Visible = true;
            }
            if (sonuc == "girisac")
            {
                panel2.Visible = false;
            }
            if (sonuc == "giriskapat")
            {
                panel2.Visible = true;
            }
            if (sonuc == "araba1var")
            {
                panel4.Visible = true;

            }
            if (sonuc == "araba1yok")
            {
                panel4.Visible = false;

            }
            if (sonuc == "araba2var")
            {
                panel5.Visible = true;

            }
            if (sonuc == "araba2yok")
            {
                panel5.Visible = false;

            }
            if (sonuc == "araba3var")
            {
                panel6.Visible = true;

            }
            if (sonuc == "araba3yok")
            {
                panel6.Visible = false;

            }
            if (sonuc == "araba4var")
            {
                panel7.Visible = true;

            }
            if (sonuc == "araba4yok")
            {
                panel7.Visible = false;

            }
            if (sonuc == "araba5var")
            {
                panel8.Visible = true;

            }
            if (sonuc == "araba5yok")
            {
                panel8.Visible = false;

            }
            if (sonuc == "araba6var")
            {
                panel9.Visible = true;

            }
            if (sonuc == "araba6yok")
            {
                panel9.Visible = false;

            }
            if (sonuc == "araba7var")
            {
                panel10.Visible = true;

            }
            if (sonuc == "araba7yok")
            {
                panel10.Visible = false;

            }


           
            /*if (!serialPort1.IsOpen)
                serialPort1.Open();
            for (int i = 1; i < 10; i++)
            {
                serialPort1.Write(i.ToString());
                string sonuc = serialPort1.ReadLine();
               sonuc = sonuc.Trim();

                switch (i)
                {

                    case 1:
                        if (sonuc == "0")
                        {
                            panel2.Visible = false;
                        }else
                        {
                            panel2.Visible = false;
                        }
                        break;
                    case 2:
                        if (sonuc == "0")
                        {
                            panel3.Visible = false;
                        }
                        else
                        {
                            panel3.Visible = false;
                        }
                        break;
                    case 3:
                        if (sonuc == "0")
                        {
                            panel4.Visible = false;
                        }
                        else
                        {
                            panel4.Visible = false;
                        }
                        break;
                    case 4:
                        if (sonuc == "0")
                        {
                            panel5.Visible = false;
                        }
                        else
                        {
                            panel5.Visible = false;
                        }
                        break;
                    case 5:
                        if (sonuc == "0")
                        {
                            panel6.Visible = false;
                        }
                        else
                        {
                            panel6.Visible = false;
                        }
                        break;
                    case 6:
                        if (sonuc == "0")
                        {
                            panel7.Visible = false;
                        }
                        else
                        {
                            panel7.Visible = false;
                        }
                        break;
                    case 7:
                        if (sonuc == "0")
                        {
                            panel8.Visible = false;
                        }
                        else
                        {
                            panel8.Visible = false;
                        }
                        break;
                    case 8:
                        if (sonuc == "0")
                        {
                            panel9.Visible = false;
                        }
                        else
                        {
                            panel9.Visible = false;
                        }
                        break;
                    case 9:
                        if (sonuc == "0")
                        {
                            panel10.Visible = false;
                        }
                        else
                        {
                            panel10.Visible = false;
                        }
                        break;
                }
               
            }*/

        }

        private void panel10_Paint(object sender, PaintEventArgs e)
        {

        }

        private void panel3_Paint(object sender, PaintEventArgs e)
        {

        }
    }
}
