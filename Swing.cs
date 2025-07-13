using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practic
{
    internal class Swing:DrawObject
    {
        public Swing(Point Location)
        {
            this.Location = Location;
            double smaller = (Location.Y + 130 - 470) / 110.0;
            Point[] vertices = { Location, new Point(Location.X, Location.Y - (int)(40 * smaller)), new Point(Location.X + (int)(40 * smaller), Location.Y - (int)(40 * smaller)), new Point(Location.X + (int)(40 * smaller), Location.Y) };
            Path.AddPolygon(vertices);
        }
        public override void Draw(Graphics g)
        {
            double smaller = (Location.Y + 130 - 470) / 110.0;

            g.DrawLine(new Pen(Color.OrangeRed, 4), Location, new Point(Location.X, Location.Y - (int)(40 * smaller)));
            g.DrawLine(new Pen(Color.OrangeRed, 4), new Point(Location.X, Location.Y - (int)(40 * smaller)), new Point(Location.X + (int)(40 * smaller), Location.Y - (int)(40 * smaller)));
            g.DrawLine(new Pen(Color.OrangeRed, 4), new Point(Location.X + (int)(40 * smaller), Location.Y - (int)(40 * smaller)), new Point(Location.X + (int)(40 * smaller), Location.Y));
            g.DrawLine(new Pen(Color.OrangeRed, 2), new Point(Location.X + (int)(12 * smaller), Location.Y - (int)(40 * smaller)), new Point(Location.X + (int)(12 * smaller), Location.Y - (int)(15 * smaller)));
            g.DrawLine(new Pen(Color.OrangeRed, 2), new Point(Location.X + (int)(28 * smaller), Location.Y - (int)(40 * smaller)), new Point(Location.X + (int)(28 * smaller), Location.Y - (int)(15 * smaller)));
            g.DrawLine(new Pen(Color.OrangeRed, 4), new Point(Location.X + (int)(8 * smaller), Location.Y - (int)(15 * smaller)), new Point(Location.X + (int)(32 * smaller), Location.Y - (int)(15 * smaller)));
        }
    }
}
