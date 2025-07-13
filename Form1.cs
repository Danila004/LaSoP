using System.Windows.Forms;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Media;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices.Marshalling;
using System.Reflection.Metadata.Ecma335;


namespace Practic
{
    public partial class Form1 : Form
    {
        List<DrawObject> drawObjects = new List<DrawObject>();
        List<DrawObject> visibleObjects = new List<DrawObject>();
        bool isDel = false;
        int countHouse = 0;
        Point location = new Point();
        SoundPlayer goodSound = new SoundPlayer("C:\\IT\\C#\\Practic\\Sounds\\good.wav");
        SoundPlayer badSound = new SoundPlayer("C:\\IT\\C#\\Practic\\Sounds\\bad.wav");
        Cursor addCursor = new Cursor("C:\\IT\\C#\\Practic\\Cursors\\add.cur");
        Cursor delCursor = new Cursor("C:\\IT\\C#\\Practic\\Cursors\\remove.cur");

        public Form1()
        {
            InitializeComponent();
            DrawingPictureBox.Image = Image.FromFile("C:\\IT\\C#\\Practic\\SourceImage.jpg");
            DrawingPictureBox.SizeMode = PictureBoxSizeMode.StretchImage;
            this.Icon = new Icon("C:\\IT\\C#\\Practic\\city.ico");
        }

        private void DelButton_Click(object sender, EventArgs e)
        {
            if (!isDel)
            {
                this.Cursor = delCursor;
                isDel = true;
                HouseCheckBox.Enabled = false;
                FlowerBedCheckBox.Enabled = false;
                StreetLightCheckBox.Enabled = false;
                SwingCheckBox.Enabled = false;
                ColorHousePictureBox.Enabled = false;
            }
            else
            {
                this.Cursor = Cursors.Default;
                isDel = false;
                HouseCheckBox.Enabled = true;
                FlowerBedCheckBox.Enabled = true;
                StreetLightCheckBox.Enabled = true;
                SwingCheckBox.Enabled = true;
                ColorHousePictureBox.Enabled = true;
            }
        }

        private void HouseCheckBox_CheckedChanged(object sender, EventArgs e)
        {
            if (HouseCheckBox.Checked)
            {
                this.Cursor = addCursor;
                FlowerBedCheckBox.Enabled = false;
                StreetLightCheckBox.Enabled = false;
                SwingCheckBox.Enabled = false;
                DelButton.Enabled = false;
            }
            else
            {
                this.Cursor = Cursors.Default;
                FlowerBedCheckBox.Enabled = true;
                StreetLightCheckBox.Enabled = true;
                SwingCheckBox.Enabled = true;
                DelButton.Enabled = true;
            }
        }

        private void FlowerBedCheckBox_CheckedChanged(object sender, EventArgs e)
        {
            if (FlowerBedCheckBox.Checked)
            {
                this.Cursor = addCursor;
                HouseCheckBox.Enabled = false;
                StreetLightCheckBox.Enabled = false;
                SwingCheckBox.Enabled = false;
                DelButton.Enabled = false;
                ColorHousePictureBox.Enabled = false;
            }
            else
            {
                this.Cursor = Cursors.Default;
                HouseCheckBox.Enabled = true;
                StreetLightCheckBox.Enabled = true;
                SwingCheckBox.Enabled = true;
                DelButton.Enabled = true;
                ColorHousePictureBox.Enabled = true;
            }
        }

        private void StreetLightCheckBox_CheckedChanged(object sender, EventArgs e)
        {
            if (StreetLightCheckBox.Checked)
            {
                this.Cursor = addCursor;
                FlowerBedCheckBox.Enabled = false;
                HouseCheckBox.Enabled = false;
                SwingCheckBox.Enabled = false;
                DelButton.Enabled = false;
                ColorHousePictureBox.Enabled = false;
            }
            else
            {
                this.Cursor = Cursors.Default;
                FlowerBedCheckBox.Enabled = true;
                HouseCheckBox.Enabled = true;
                SwingCheckBox.Enabled = true;
                DelButton.Enabled = true;
                ColorHousePictureBox.Enabled = true;
            }
        }

        private void SwingCheckBox_CheckedChanged(object sender, EventArgs e)
        {
            if (SwingCheckBox.Checked)
            {
                this.Cursor = addCursor;
                FlowerBedCheckBox.Enabled = false;
                StreetLightCheckBox.Enabled = false;
                HouseCheckBox.Enabled = false;
                DelButton.Enabled = false;
                ColorHousePictureBox.Enabled = false;
            }
            else
            {
                this.Cursor = Cursors.Default;
                FlowerBedCheckBox.Enabled = true;
                StreetLightCheckBox.Enabled = true;
                HouseCheckBox.Enabled = true;
                DelButton.Enabled = true;
                ColorHousePictureBox.Enabled = true;
            }
        }

        private void ColorHousePictureBox_Click(object sender, EventArgs e)
        {
            using (ColorDialog color = new ColorDialog())
            {
                if (color.ShowDialog() == DialogResult.OK)
                    ColorHousePictureBox.BackColor = color.Color;
            }
        }

        private void DrawingPictureBox_MouseClick(object sender, MouseEventArgs e)
        {
            if (e.Location.Y >= 350 && e.Location.Y <= 470)
            {
                visibleObjects = drawObjects.Where(elem => elem.IsVisible(e.Location)).ToList();
                if ((HouseCheckBox.Checked || FlowerBedCheckBox.Checked || StreetLightCheckBox.Checked || SwingCheckBox.Checked) && visibleObjects.Count() == 0 || 
                    isDel && visibleObjects.Count() != 0)
                {
                    goodSound.Play();
                    location = e.Location;
                    this.InvokePaint(DrawingPictureBox, new PaintEventArgs(DrawingPictureBox.CreateGraphics(), DrawingPictureBox.ClientRectangle));
                }
                else badSound.Play();
            }
            else badSound.Play();
        }

        private void DrawingPictureBox_Paint(object sender, PaintEventArgs e)
        { 
            
            if (HouseCheckBox.Checked)
            {
                House house = new House(location, ColorHousePictureBox.BackColor);  
                drawObjects.Add(house);
                PeopleInCityLabel.Text = $"Человек в городе: {++countHouse * 50}";
            }
            else if (FlowerBedCheckBox.Checked)
            {
                FlowerBed flowerbed = new FlowerBed(location);
                drawObjects.Add(flowerbed);
            }
            else if (StreetLightCheckBox.Checked)
            {
                StreetLight streetlight = new StreetLight(location);
                drawObjects.Add(streetlight);
            }
            else if (SwingCheckBox.Checked)
            {
                Swing swing = new Swing(location);
                drawObjects.Add(swing);
            }
            else if(isDel)
            {
                if(visibleObjects.Count == 1)
                    drawObjects.Remove(visibleObjects[0]);
                else
                {
                    DrawObject objectForDel = visibleObjects.OrderByDescending(elem => elem.Location.Y).First();
                    drawObjects.Remove(objectForDel);
                }
            }
            if(!isDel) drawObjects.Sort((x, y) => x.Location.Y.CompareTo(y.Location.Y));
            foreach (var i in drawObjects)
                i.Draw(e.Graphics);
        }
    }
}
