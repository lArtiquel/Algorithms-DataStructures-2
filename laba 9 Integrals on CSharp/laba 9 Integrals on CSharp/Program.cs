﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;

namespace laba_9_Integrals_on_CSharp
{
    static class Program
    {
        /// <summary>
        /// Главная точка входа для приложения.
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
}
