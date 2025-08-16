namespace WindowsFormsApp1
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.DivBtn = new System.Windows.Forms.RadioButton();
            this.SumBtn = new System.Windows.Forms.RadioButton();
            this.SubBtn = new System.Windows.Forms.RadioButton();
            this.MultBtn = new System.Windows.Forms.RadioButton();
            this.CalcBtn = new System.Windows.Forms.Button();
            this.ValTxtBx2 = new System.Windows.Forms.TextBox();
            this.ValTxtBx1 = new System.Windows.Forms.TextBox();
            this.ExitBtn = new System.Windows.Forms.Button();
            this.ResLbl = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // DivBtn
            // 
            this.DivBtn.AutoSize = true;
            this.DivBtn.Location = new System.Drawing.Point(585, 151);
            this.DivBtn.Name = "DivBtn";
            this.DivBtn.Size = new System.Drawing.Size(88, 24);
            this.DivBtn.TabIndex = 0;
            this.DivBtn.TabStop = true;
            this.DivBtn.Text = "Division";
            this.DivBtn.UseVisualStyleBackColor = true;
            // 
            // SumBtn
            // 
            this.SumBtn.AutoSize = true;
            this.SumBtn.Location = new System.Drawing.Point(585, 60);
            this.SumBtn.Name = "SumBtn";
            this.SumBtn.Size = new System.Drawing.Size(67, 24);
            this.SumBtn.TabIndex = 1;
            this.SumBtn.TabStop = true;
            this.SumBtn.Text = "Sum";
            this.SumBtn.UseVisualStyleBackColor = true;
            // 
            // SubBtn
            // 
            this.SubBtn.AutoSize = true;
            this.SubBtn.Location = new System.Drawing.Point(585, 90);
            this.SubBtn.Name = "SubBtn";
            this.SubBtn.Size = new System.Drawing.Size(103, 24);
            this.SubBtn.TabIndex = 2;
            this.SubBtn.TabStop = true;
            this.SubBtn.Text = "Substract";
            this.SubBtn.UseVisualStyleBackColor = true;
            // 
            // MultBtn
            // 
            this.MultBtn.AutoSize = true;
            this.MultBtn.Location = new System.Drawing.Point(585, 121);
            this.MultBtn.Name = "MultBtn";
            this.MultBtn.Size = new System.Drawing.Size(86, 24);
            this.MultBtn.TabIndex = 3;
            this.MultBtn.TabStop = true;
            this.MultBtn.Text = "Multiply";
            this.MultBtn.UseVisualStyleBackColor = true;
            // 
            // CalcBtn
            // 
            this.CalcBtn.Location = new System.Drawing.Point(377, 152);
            this.CalcBtn.Name = "CalcBtn";
            this.CalcBtn.Size = new System.Drawing.Size(86, 29);
            this.CalcBtn.TabIndex = 4;
            this.CalcBtn.Text = "Calculate";
            this.CalcBtn.UseVisualStyleBackColor = true;
            this.CalcBtn.Click += new System.EventHandler(this.CalcBtn_Click);
            // 
            // ValTxtBx2
            // 
            this.ValTxtBx2.Location = new System.Drawing.Point(363, 92);
            this.ValTxtBx2.Name = "ValTxtBx2";
            this.ValTxtBx2.Size = new System.Drawing.Size(100, 26);
            this.ValTxtBx2.TabIndex = 5;
            // 
            // ValTxtBx1
            // 
            this.ValTxtBx1.Location = new System.Drawing.Point(363, 60);
            this.ValTxtBx1.Name = "ValTxtBx1";
            this.ValTxtBx1.Size = new System.Drawing.Size(100, 26);
            this.ValTxtBx1.TabIndex = 6;
            // 
            // ExitBtn
            // 
            this.ExitBtn.Location = new System.Drawing.Point(377, 187);
            this.ExitBtn.Name = "ExitBtn";
            this.ExitBtn.Size = new System.Drawing.Size(86, 28);
            this.ExitBtn.TabIndex = 4;
            this.ExitBtn.Text = "Exit";
            this.ExitBtn.UseVisualStyleBackColor = true;
            this.ExitBtn.Click += new System.EventHandler(this.ExitBtn_Click);
            // 
            // ResLbl
            // 
            this.ResLbl.AutoSize = true;
            this.ResLbl.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ResLbl.Location = new System.Drawing.Point(572, 195);
            this.ResLbl.Name = "ResLbl";
            this.ResLbl.Size = new System.Drawing.Size(95, 32);
            this.ResLbl.TabIndex = 7;
            this.ResLbl.Text = "Result";
            // 
            // Form1
            // 
            this.ClientSize = new System.Drawing.Size(897, 615);
            this.Controls.Add(this.ResLbl);
            this.Controls.Add(this.ValTxtBx1);
            this.Controls.Add(this.ValTxtBx2);
            this.Controls.Add(this.ExitBtn);
            this.Controls.Add(this.CalcBtn);
            this.Controls.Add(this.MultBtn);
            this.Controls.Add(this.SubBtn);
            this.Controls.Add(this.SumBtn);
            this.Controls.Add(this.DivBtn);
            this.Name = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load_1);
            this.ResumeLayout(false);
            this.PerformLayout();

        }


        #endregion

        private System.Windows.Forms.RadioButton DivBtn;
        private System.Windows.Forms.RadioButton SumBtn;
        private System.Windows.Forms.RadioButton SubBtn;
        private System.Windows.Forms.RadioButton MultBtn;
        private System.Windows.Forms.Button CalcBtn;
        private System.Windows.Forms.TextBox ValTxtBx2;
        private System.Windows.Forms.TextBox ValTxtBx1;
        private System.Windows.Forms.Button ExitBtn;
        private System.Windows.Forms.Label ResLbl;
    }
}

