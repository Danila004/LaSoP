using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practic
{
    internal class House: DrawObject
    {
        Color color;
        public House(Point Location, Color color)
        {
            this.Location = Location;
            this.color = color;
            double smaller = (Location.Y + 130 - 470) / 110.0;
            Point[] vertices = { Location, new Point(Location.X, Location.Y - (int)(150 * smaller)), new Point(Location.X + (int)(60 * smaller), Location.Y - (int)(150 * smaller)), new Point(Location.X + (int)(60 * smaller), Location.Y) };
            Path.AddPolygon(vertices);
        }
        public override void Draw(Graphics g)
        {
            double smaller = (Location.Y + 130 - 470) / 110.0;
            SolidBrush background = new SolidBrush(color);

            Point[] vertices = { Location, new Point(Location.X, Location.Y - (int)(150 * smaller)), new Point(Location.X + (int)(60 * smaller), Location.Y - (int)(150 * smaller)), new Point(Location.X + (int)(60 * smaller), Location.Y) };
            g.FillPolygon(background, vertices);
            Point[] door = { new Point(Location.X + (int)(15 * smaller), Location.Y), new Point(Location.X + (int)(15 * smaller), Location.Y - (int)(20 * smaller)), new Point(Location.X + (int)(45 * smaller), Location.Y - (int)(20 * smaller)), new Point(Location.X + (int)(45 * smaller), Location.Y) };
            g.DrawPolygon(new Pen(Color.Black, 2), door);
            g.DrawPolygon(new Pen(Color.Black, 2), vertices);

            g.DrawLine(new Pen(Color.Black, 2), new Point(Location.X, Location.Y - (int)(120 * smaller)), new Point(Location.X + (int)(60 * smaller), Location.Y - (int)(120 * smaller)));
            g.DrawLine(new Pen(Color.Black, 2), new Point(Location.X, Location.Y - (int)(90 * smaller)), new Point(Location.X + (int)(60 * smaller), Location.Y - (int)(90 * smaller)));
            g.DrawLine(new Pen(Color.Black, 2), new Point(Location.X, Location.Y - (int)(60 * smaller)), new Point(Location.X + (int)(60 * smaller), Location.Y - (int)(60 * smaller)));
            g.DrawLine(new Pen(Color.Black, 2), new Point(Location.X, Location.Y - (int)(30 * smaller)), new Point(Location.X + (int)(60 * smaller), Location.Y - (int)(30 * smaller)));
            g.DrawLine(new Pen(Color.Black, 2), new Point(Location.X + (int)(18 * smaller), Location.Y - (int)(150 * smaller)), new Point(Location.X + (int)(18 * smaller), Location.Y - (int)(30 * smaller)));
            g.DrawLine(new Pen(Color.Black, 2), new Point(Location.X + (int)(42 * smaller), Location.Y - (int)(150 * smaller)), new Point(Location.X + (int)(42 * smaller), Location.Y - (int)(30 * smaller)));
            g.DrawLine(new Pen(Color.Black, 2), new Point(Location.X, Location.Y - (int)(135 * smaller)), new Point(Location.X + (int)(60 * smaller), Location.Y - (int)(135 * smaller)));
            g.DrawLine(new Pen(Color.Black, 2), new Point(Location.X, Location.Y - (int)(105 * smaller)), new Point(Location.X + (int)(60 * smaller), Location.Y - (int)(105 * smaller)));
            g.DrawLine(new Pen(Color.Black, 2), new Point(Location.X, Location.Y - (int)(75 * smaller)), new Point(Location.X + (int)(60 * smaller), Location.Y - (int)(75 * smaller)));
            g.DrawLine(new Pen(Color.Black, 2), new Point(Location.X, Location.Y - (int)(45 * smaller)), new Point(Location.X + (int)(60 * smaller), Location.Y - (int)(45 * smaller)));
        }
    }
}
