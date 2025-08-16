namespace WindowsFormsApp2
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
            this.PizzaToppingGrp = new System.Windows.Forms.GroupBox();
            this.GPepCB = new System.Windows.Forms.CheckBox();
            this.TomaCB = new System.Windows.Forms.CheckBox();
            this.OniCB = new System.Windows.Forms.CheckBox();
            this.MushCB = new System.Windows.Forms.CheckBox();
            this.PizzaSizeGrp = new System.Windows.Forms.GroupBox();
            this.LargeRB = new System.Windows.Forms.RadioButton();
            this.MediumRB = new System.Windows.Forms.RadioButton();
            this.SmallRB = new System.Windows.Forms.RadioButton();
            this.PizzaTypeGrp = new System.Windows.Forms.GroupBox();
            this.VeganRB = new System.Windows.Forms.RadioButton();
            this.SupRB = new System.Windows.Forms.RadioButton();
            this.CapriRB = new System.Windows.Forms.RadioButton();
            this.BuildPizzaLbl = new System.Windows.Forms.Label();
            this.YourPizzaLbl = new System.Windows.Forms.Label();
            this.BuildBtn = new System.Windows.Forms.Button();
            this.ExitBtn = new System.Windows.Forms.Button();
            this.ChangeBtn = new System.Windows.Forms.Button();
            this.BillBtn = new System.Windows.Forms.Button();
            this.PizzaPartsLbl = new System.Windows.Forms.Label();
            this.PizzaToppingGrp.SuspendLayout();
            this.PizzaSizeGrp.SuspendLayout();
            this.PizzaTypeGrp.SuspendLayout();
            this.SuspendLayout();
            // 
            // PizzaToppingGrp
            // 
            this.PizzaToppingGrp.Controls.Add(this.GPepCB);
            this.PizzaToppingGrp.Controls.Add(this.TomaCB);
            this.PizzaToppingGrp.Controls.Add(this.OniCB);
            this.PizzaToppingGrp.Controls.Add(this.MushCB);
            this.PizzaToppingGrp.Location = new System.Drawing.Point(263, 258);
            this.PizzaToppingGrp.Name = "PizzaToppingGrp";
            this.PizzaToppingGrp.Size = new System.Drawing.Size(401, 122);
            this.PizzaToppingGrp.TabIndex = 0;
            this.PizzaToppingGrp.TabStop = false;
            this.PizzaToppingGrp.Text = "Topping";
            this.PizzaToppingGrp.Enter += new System.EventHandler(this.PizzaToppingGrp_Enter);
            // 
            // GPepCB
            // 
            this.GPepCB.AutoSize = true;
            this.GPepCB.Location = new System.Drawing.Point(222, 83);
            this.GPepCB.Name = "GPepCB";
            this.GPepCB.Size = new System.Drawing.Size(143, 24);
            this.GPepCB.TabIndex = 0;
            this.GPepCB.Text = "Green Peppers";
            this.GPepCB.UseVisualStyleBackColor = true;
            // 
            // TomaCB
            // 
            this.TomaCB.AutoSize = true;
            this.TomaCB.Location = new System.Drawing.Point(27, 83);
            this.TomaCB.Name = "TomaCB";
            this.TomaCB.Size = new System.Drawing.Size(106, 24);
            this.TomaCB.TabIndex = 0;
            this.TomaCB.Text = "Tomatoes";
            this.TomaCB.UseVisualStyleBackColor = true;
            // 
            // OniCB
            // 
            this.OniCB.AutoSize = true;
            this.OniCB.Location = new System.Drawing.Point(222, 43);
            this.OniCB.Name = "OniCB";
            this.OniCB.Size = new System.Drawing.Size(85, 24);
            this.OniCB.TabIndex = 0;
            this.OniCB.Text = "Onions";
            this.OniCB.UseVisualStyleBackColor = true;
            // 
            // MushCB
            // 
            this.MushCB.AutoSize = true;
            this.MushCB.Location = new System.Drawing.Point(27, 42);
            this.MushCB.Name = "MushCB";
            this.MushCB.Size = new System.Drawing.Size(118, 24);
            this.MushCB.TabIndex = 0;
            this.MushCB.Text = "Mushrooms";
            this.MushCB.UseVisualStyleBackColor = true;
            this.MushCB.CheckedChanged += new System.EventHandler(this.checkBox1_CheckedChanged);
            // 
            // PizzaSizeGrp
            // 
            this.PizzaSizeGrp.Controls.Add(this.LargeRB);
            this.PizzaSizeGrp.Controls.Add(this.MediumRB);
            this.PizzaSizeGrp.Controls.Add(this.SmallRB);
            this.PizzaSizeGrp.Location = new System.Drawing.Point(26, 223);
            this.PizzaSizeGrp.Name = "PizzaSizeGrp";
            this.PizzaSizeGrp.Size = new System.Drawing.Size(149, 157);
            this.PizzaSizeGrp.TabIndex = 1;
            this.PizzaSizeGrp.TabStop = false;
            this.PizzaSizeGrp.Text = "Pizza Size";
            this.PizzaSizeGrp.Enter += new System.EventHandler(this.PizzaSizeGrp_Enter);
            // 
            // LargeRB
            // 
            this.LargeRB.AutoSize = true;
            this.LargeRB.Location = new System.Drawing.Point(6, 118);
            this.LargeRB.Name = "LargeRB";
            this.LargeRB.Size = new System.Drawing.Size(75, 24);
            this.LargeRB.TabIndex = 0;
            this.LargeRB.TabStop = true;
            this.LargeRB.Text = "Large";
            this.LargeRB.UseVisualStyleBackColor = true;
            // 
            // MediumRB
            // 
            this.MediumRB.AutoSize = true;
            this.MediumRB.Location = new System.Drawing.Point(6, 77);
            this.MediumRB.Name = "MediumRB";
            this.MediumRB.Size = new System.Drawing.Size(90, 24);
            this.MediumRB.TabIndex = 0;
            this.MediumRB.TabStop = true;
            this.MediumRB.Text = "Medium";
            this.MediumRB.UseVisualStyleBackColor = true;
            this.MediumRB.CheckedChanged += new System.EventHandler(this.radioButton5_CheckedChanged);
            // 
            // SmallRB
            // 
            this.SmallRB.AutoSize = true;
            this.SmallRB.Location = new System.Drawing.Point(6, 35);
            this.SmallRB.Name = "SmallRB";
            this.SmallRB.Size = new System.Drawing.Size(73, 24);
            this.SmallRB.TabIndex = 0;
            this.SmallRB.TabStop = true;
            this.SmallRB.Text = "Small";
            this.SmallRB.UseVisualStyleBackColor = true;
            this.SmallRB.CheckedChanged += new System.EventHandler(this.radioButton4_CheckedChanged);
            // 
            // PizzaTypeGrp
            // 
            this.PizzaTypeGrp.Controls.Add(this.VeganRB);
            this.PizzaTypeGrp.Controls.Add(this.SupRB);
            this.PizzaTypeGrp.Controls.Add(this.CapriRB);
            this.PizzaTypeGrp.Location = new System.Drawing.Point(26, 53);
            this.PizzaTypeGrp.Name = "PizzaTypeGrp";
            this.PizzaTypeGrp.Size = new System.Drawing.Size(149, 164);
            this.PizzaTypeGrp.TabIndex = 1;
            this.PizzaTypeGrp.TabStop = false;
            this.PizzaTypeGrp.Text = "Pizza Type";
            this.PizzaTypeGrp.Enter += new System.EventHandler(this.groupBox3_Enter);
            // 
            // VeganRB
            // 
            this.VeganRB.AutoSize = true;
            this.VeganRB.Location = new System.Drawing.Point(6, 32);
            this.VeganRB.Name = "VeganRB";
            this.VeganRB.Size = new System.Drawing.Size(112, 24);
            this.VeganRB.TabIndex = 0;
            this.VeganRB.TabStop = true;
            this.VeganRB.Text = "Vegeterian";
            this.VeganRB.UseVisualStyleBackColor = true;
            this.VeganRB.CheckedChanged += new System.EventHandler(this.radioButton2_CheckedChanged);
            // 
            // SupRB
            // 
            this.SupRB.AutoSize = true;
            this.SupRB.Location = new System.Drawing.Point(6, 113);
            this.SupRB.Name = "SupRB";
            this.SupRB.Size = new System.Drawing.Size(99, 24);
            this.SupRB.TabIndex = 0;
            this.SupRB.TabStop = true;
            this.SupRB.Text = "Supreme";
            this.SupRB.UseVisualStyleBackColor = true;
            // 
            // CapriRB
            // 
            this.CapriRB.AutoSize = true;
            this.CapriRB.Location = new System.Drawing.Point(6, 73);
            this.CapriRB.Name = "CapriRB";
            this.CapriRB.Size = new System.Drawing.Size(116, 24);
            this.CapriRB.TabIndex = 0;
            this.CapriRB.TabStop = true;
            this.CapriRB.Text = "Capricciosa";
            this.CapriRB.UseVisualStyleBackColor = true;
            this.CapriRB.CheckedChanged += new System.EventHandler(this.radioButton1_CheckedChanged);
            // 
            // BuildPizzaLbl
            // 
            this.BuildPizzaLbl.AutoSize = true;
            this.BuildPizzaLbl.Font = new System.Drawing.Font("Microsoft Sans Serif", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.BuildPizzaLbl.Location = new System.Drawing.Point(343, 21);
            this.BuildPizzaLbl.Name = "BuildPizzaLbl";
            this.BuildPizzaLbl.Size = new System.Drawing.Size(175, 37);
            this.BuildPizzaLbl.TabIndex = 2;
            this.BuildPizzaLbl.Text = "Build Pizza";
            // 
            // YourPizzaLbl
            // 
            this.YourPizzaLbl.AutoSize = true;
            this.YourPizzaLbl.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.YourPizzaLbl.Location = new System.Drawing.Point(376, 83);
            this.YourPizzaLbl.Name = "YourPizzaLbl";
            this.YourPizzaLbl.Size = new System.Drawing.Size(0, 25);
            this.YourPizzaLbl.TabIndex = 3;
            // 
            // BuildBtn
            // 
            this.BuildBtn.Location = new System.Drawing.Point(160, 402);
            this.BuildBtn.Name = "BuildBtn";
            this.BuildBtn.Size = new System.Drawing.Size(86, 36);
            this.BuildBtn.TabIndex = 5;
            this.BuildBtn.Text = "Build";
            this.BuildBtn.UseVisualStyleBackColor = true;
            this.BuildBtn.Click += new System.EventHandler(this.BuildBtn_Click);
            // 
            // ExitBtn
            // 
            this.ExitBtn.Location = new System.Drawing.Point(299, 402);
            this.ExitBtn.Name = "ExitBtn";
            this.ExitBtn.Size = new System.Drawing.Size(88, 36);
            this.ExitBtn.TabIndex = 6;
            this.ExitBtn.Text = "Exit";
            this.ExitBtn.UseVisualStyleBackColor = true;
            this.ExitBtn.Click += new System.EventHandler(this.ExitBtn_Click);
            // 
            // ChangeBtn
            // 
            this.ChangeBtn.Location = new System.Drawing.Point(426, 402);
            this.ChangeBtn.Name = "ChangeBtn";
            this.ChangeBtn.Size = new System.Drawing.Size(75, 36);
            this.ChangeBtn.TabIndex = 7;
            this.ChangeBtn.Text = "Change";
            this.ChangeBtn.UseVisualStyleBackColor = true;
            this.ChangeBtn.Click += new System.EventHandler(this.ChangeBtn_Click);
            // 
            // BillBtn
            // 
            this.BillBtn.Location = new System.Drawing.Point(566, 402);
            this.BillBtn.Name = "BillBtn";
            this.BillBtn.Size = new System.Drawing.Size(75, 36);
            this.BillBtn.TabIndex = 7;
            this.BillBtn.Text = "Bill";
            this.BillBtn.UseVisualStyleBackColor = true;
            this.BillBtn.Click += new System.EventHandler(this.BillBtn_Click);
            // 
            // PizzaPartsLbl
            // 
            this.PizzaPartsLbl.AutoSize = true;
            this.PizzaPartsLbl.Location = new System.Drawing.Point(395, 130);
            this.PizzaPartsLbl.Name = "PizzaPartsLbl";
            this.PizzaPartsLbl.Size = new System.Drawing.Size(0, 20);
            this.PizzaPartsLbl.TabIndex = 8;
            this.PizzaPartsLbl.Visible = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.PizzaPartsLbl);
            this.Controls.Add(this.BillBtn);
            this.Controls.Add(this.ChangeBtn);
            this.Controls.Add(this.ExitBtn);
            this.Controls.Add(this.BuildBtn);
            this.Controls.Add(this.YourPizzaLbl);
            this.Controls.Add(this.BuildPizzaLbl);
            this.Controls.Add(this.PizzaTypeGrp);
            this.Controls.Add(this.PizzaSizeGrp);
            this.Controls.Add(this.PizzaToppingGrp);
            this.Name = "Form1";
            this.Text = "Form1";
            this.PizzaToppingGrp.ResumeLayout(false);
            this.PizzaToppingGrp.PerformLayout();
            this.PizzaSizeGrp.ResumeLayout(false);
            this.PizzaSizeGrp.PerformLayout();
            this.PizzaTypeGrp.ResumeLayout(false);
            this.PizzaTypeGrp.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.GroupBox PizzaToppingGrp;
        private System.Windows.Forms.GroupBox PizzaSizeGrp;
        private System.Windows.Forms.GroupBox PizzaTypeGrp;
        private System.Windows.Forms.Label BuildPizzaLbl;
        private System.Windows.Forms.Label YourPizzaLbl;
        private System.Windows.Forms.Button BuildBtn;
        private System.Windows.Forms.Button ExitBtn;
        private System.Windows.Forms.Button ChangeBtn;
        private System.Windows.Forms.RadioButton LargeRB;
        private System.Windows.Forms.RadioButton MediumRB;
        private System.Windows.Forms.RadioButton SmallRB;
        private System.Windows.Forms.RadioButton VeganRB;
        private System.Windows.Forms.RadioButton SupRB;
        private System.Windows.Forms.RadioButton CapriRB;
        private System.Windows.Forms.CheckBox GPepCB;
        private System.Windows.Forms.CheckBox TomaCB;
        private System.Windows.Forms.CheckBox OniCB;
        private System.Windows.Forms.CheckBox MushCB;
        private System.Windows.Forms.Button BillBtn;
        private System.Windows.Forms.Label PizzaPartsLbl;
    }
}

