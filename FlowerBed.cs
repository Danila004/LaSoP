using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practic
{
    internal class FlowerBed: DrawObject
    {
        public FlowerBed(Point Location)
        {
            this.Location = Location;
            double smaller = (Location.Y + 130 - 470) / 110.0;
            Point[] vertices = { Location, new Point(Location.X, Location.Y - (int)(30 * smaller)), new Point(Location.X + (int)(30 * smaller), Location.Y - (int)(30 * smaller)), new Point(Location.X + (int)(30 * smaller), Location.Y) };
            Path.AddPolygon(vertices);
        }
        public override void Draw(Graphics g)
        {
            double smaller = (Location.Y + 130 - 470) / 110.0;

            Point[] vertices = { Location, new Point(Location.X, Location.Y - (int)(30 * smaller)), 
                new Point(Location.X + (int)(30 * smaller), Location.Y - (int)(30 * smaller)), 
                new Point(Location.X + (int)(30 * smaller), Location.Y) };
            g.FillPolygon(Brushes.Brown, vertices);
            g.DrawPolygon(new Pen(Color.Black, 2), vertices);

            Rectangle flower = new Rectangle(Location.X + (int)(5 * smaller), Location.Y - (int)(25 * smaller), 
                (int)(20 * smaller), (int)(20 * smaller));
            g.FillPie(Brushes.Yellow, flower, 0, 360);
        }
    }
}
