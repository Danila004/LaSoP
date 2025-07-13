using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practic
{
    internal class StreetLight:DrawObject
    {
        public StreetLight(Point Location) 
        {
            this.Location = Location;
            double smaller = (Location.Y + 130 - 470) / 110.0;
            Point[] vertices = { new Point(Location.X - (int)(7 * smaller), Location.Y), new Point(Location.X - (int)(7 * smaller), Location.Y - (int)(50 * smaller)), new Point(Location.X + (int)(13 * smaller), Location.Y - (int)(50 * smaller)), new Point(Location.X + (int)(13 * smaller), Location.Y) };
            Path.AddPolygon(vertices);
        }
        public override void Draw(Graphics g)
        {
            double smaller = (Location.Y + 130 - 470) / 110.0;

            Point[] vertices = { Location, new Point(Location.X, Location.Y- (int)(30*smaller)), new Point(Location.X- (int)(7*smaller),Location.Y- (int)(30*smaller)), new Point(Location.X- (int)(7*smaller), Location.Y- (int)(50*smaller)), new Point(Location.X+ (int)(13*smaller), Location.Y- (int)(50*smaller)),
                new Point(Location.X+ (int)(13*smaller), Location.Y- (int)(30*smaller)), new Point(Location.X+ (int)(6*smaller), Location.Y- (int)(30*smaller)), new Point(Location.X+ (int)(6*smaller), Location.Y) };
            g.FillPolygon(Brushes.Black, vertices);
            Point[] light = { new Point(Location.X - (int)(2 * smaller), Location.Y - (int)(35 * smaller)), new Point(Location.X - (int)(2 * smaller), Location.Y - (int)(45 * smaller)), new Point(Location.X + (int)(8 * smaller), Location.Y - (int)(45 * smaller)), new Point(Location.X + (int)(8 * smaller), Location.Y - (int)(35 * smaller)) };
            g.FillPolygon(Brushes.Yellow, light);
        }
    }
}
