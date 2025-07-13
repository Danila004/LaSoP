using System;
using System.Collections.Generic;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Practic
{
    abstract internal class DrawObject
    {
        protected GraphicsPath Path = new GraphicsPath();
        public Point Location = new Point();
        abstract public void Draw(Graphics g);
        public bool IsVisible(Point point)
        {
            return Path.IsVisible(point);
        }
    }
}
