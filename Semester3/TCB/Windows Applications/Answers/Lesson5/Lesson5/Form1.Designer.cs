namespace Lesson5
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
            this.FindEngBTN = new System.Windows.Forms.Button();
            this.ClearBTN = new System.Windows.Forms.Button();
            this.FindHebBTN = new System.Windows.Forms.Button();
            this.AddBTN = new System.Windows.Forms.Button();
            this.ShowDicBTN = new System.Windows.Forms.Button();
            this.AddWordLBL = new System.Windows.Forms.Label();
            this.FindEngLBL = new System.Windows.Forms.Label();
            this.FindHebLBL = new System.Windows.Forms.Label();
            this.AddHebLBL = new System.Windows.Forms.Label();
            this.AddEngLBL = new System.Windows.Forms.Label();
            this.FindEngHebLBL = new System.Windows.Forms.Label();
            this.FindEngEngLBL = new System.Windows.Forms.Label();
            this.FindHebEngLBL = new System.Windows.Forms.Label();
            this.FindHebHebLBL = new System.Windows.Forms.Label();
            this.AddHebTB = new System.Windows.Forms.TextBox();
            this.AddEngTB = new System.Windows.Forms.TextBox();
            this.FindEngHebTB = new System.Windows.Forms.TextBox();
            this.FindEngEngTB = new System.Windows.Forms.TextBox();
            this.FindHebEngTB = new System.Windows.Forms.TextBox();
            this.FindHebHebTB = new System.Windows.Forms.TextBox();
            this.WordIB = new System.Windows.Forms.PictureBox();
            this.UploadPicBTN = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.WordIB)).BeginInit();
            this.SuspendLayout();
            // 
            // FindEngBTN
            // 
            this.FindEngBTN.Location = new System.Drawing.Point(318, 198);
            this.FindEngBTN.Name = "FindEngBTN";
            this.FindEngBTN.Size = new System.Drawing.Size(186, 32);
            this.FindEngBTN.TabIndex = 0;
            this.FindEngBTN.Text = "Find";
            this.FindEngBTN.UseVisualStyleBackColor = true;
            this.FindEngBTN.Click += new System.EventHandler(this.FindEngBTN_Click);
            // 
            // ClearBTN
            // 
            this.ClearBTN.Location = new System.Drawing.Point(307, 335);
            this.ClearBTN.Name = "ClearBTN";
            this.ClearBTN.Size = new System.Drawing.Size(186, 32);
            this.ClearBTN.TabIndex = 1;
            this.ClearBTN.Text = "Clear";
            this.ClearBTN.UseVisualStyleBackColor = true;
            this.ClearBTN.Click += new System.EventHandler(this.ClearBTN_Click);
            // 
            // FindHebBTN
            // 
            this.FindHebBTN.Location = new System.Drawing.Point(548, 198);
            this.FindHebBTN.Name = "FindHebBTN";
            this.FindHebBTN.Size = new System.Drawing.Size(186, 32);
            this.FindHebBTN.TabIndex = 2;
            this.FindHebBTN.Text = "Find";
            this.FindHebBTN.UseVisualStyleBackColor = true;
            this.FindHebBTN.Click += new System.EventHandler(this.FindHebBTN_Click);
            // 
            // AddBTN
            // 
            this.AddBTN.Location = new System.Drawing.Point(44, 198);
            this.AddBTN.Name = "AddBTN";
            this.AddBTN.Size = new System.Drawing.Size(186, 32);
            this.AddBTN.TabIndex = 3;
            this.AddBTN.Text = "Add";
            this.AddBTN.UseVisualStyleBackColor = true;
            this.AddBTN.Click += new System.EventHandler(this.AddBTN_Click);
            // 
            // ShowDicBTN
            // 
            this.ShowDicBTN.Location = new System.Drawing.Point(307, 297);
            this.ShowDicBTN.Name = "ShowDicBTN";
            this.ShowDicBTN.Size = new System.Drawing.Size(186, 32);
            this.ShowDicBTN.TabIndex = 4;
            this.ShowDicBTN.Text = "Show Dictionary";
            this.ShowDicBTN.UseVisualStyleBackColor = true;
            this.ShowDicBTN.Click += new System.EventHandler(this.ShowDicBTN_Click);
            // 
            // AddWordLBL
            // 
            this.AddWordLBL.AutoSize = true;
            this.AddWordLBL.Location = new System.Drawing.Point(89, 25);
            this.AddWordLBL.Name = "AddWordLBL";
            this.AddWordLBL.Size = new System.Drawing.Size(84, 20);
            this.AddWordLBL.TabIndex = 5;
            this.AddWordLBL.Text = "Add Word ";
            // 
            // FindEngLBL
            // 
            this.FindEngLBL.AutoSize = true;
            this.FindEngLBL.Location = new System.Drawing.Point(357, 25);
            this.FindEngLBL.Name = "FindEngLBL";
            this.FindEngLBL.Size = new System.Drawing.Size(148, 20);
            this.FindEngLBL.TabIndex = 6;
            this.FindEngLBL.Text = "Find Word (English)";
            // 
            // FindHebLBL
            // 
            this.FindHebLBL.AutoSize = true;
            this.FindHebLBL.Location = new System.Drawing.Point(620, 25);
            this.FindHebLBL.Name = "FindHebLBL";
            this.FindHebLBL.Size = new System.Drawing.Size(151, 20);
            this.FindHebLBL.TabIndex = 7;
            this.FindHebLBL.Text = "Find Word (Hebrew)";
            // 
            // AddHebLBL
            // 
            this.AddHebLBL.AutoSize = true;
            this.AddHebLBL.Location = new System.Drawing.Point(40, 83);
            this.AddHebLBL.Name = "AddHebLBL";
            this.AddHebLBL.Size = new System.Drawing.Size(64, 20);
            this.AddHebLBL.TabIndex = 8;
            this.AddHebLBL.Text = "Hebrew";
            // 
            // AddEngLBL
            // 
            this.AddEngLBL.AutoSize = true;
            this.AddEngLBL.Location = new System.Drawing.Point(40, 124);
            this.AddEngLBL.Name = "AddEngLBL";
            this.AddEngLBL.Size = new System.Drawing.Size(61, 20);
            this.AddEngLBL.TabIndex = 8;
            this.AddEngLBL.Text = "English";
            // 
            // FindEngHebLBL
            // 
            this.FindEngHebLBL.AutoSize = true;
            this.FindEngHebLBL.Location = new System.Drawing.Point(314, 83);
            this.FindEngHebLBL.Name = "FindEngHebLBL";
            this.FindEngHebLBL.Size = new System.Drawing.Size(64, 20);
            this.FindEngHebLBL.TabIndex = 8;
            this.FindEngHebLBL.Text = "Hebrew";
            // 
            // FindEngEngLBL
            // 
            this.FindEngEngLBL.AutoSize = true;
            this.FindEngEngLBL.Location = new System.Drawing.Point(314, 124);
            this.FindEngEngLBL.Name = "FindEngEngLBL";
            this.FindEngEngLBL.Size = new System.Drawing.Size(61, 20);
            this.FindEngEngLBL.TabIndex = 8;
            this.FindEngEngLBL.Text = "English";
            // 
            // FindHebEngLBL
            // 
            this.FindHebEngLBL.AutoSize = true;
            this.FindHebEngLBL.Location = new System.Drawing.Point(544, 83);
            this.FindHebEngLBL.Name = "FindHebEngLBL";
            this.FindHebEngLBL.Size = new System.Drawing.Size(61, 20);
            this.FindHebEngLBL.TabIndex = 8;
            this.FindHebEngLBL.Text = "English";
            // 
            // FindHebHebLBL
            // 
            this.FindHebHebLBL.AutoSize = true;
            this.FindHebHebLBL.Location = new System.Drawing.Point(544, 124);
            this.FindHebHebLBL.Name = "FindHebHebLBL";
            this.FindHebHebLBL.Size = new System.Drawing.Size(64, 20);
            this.FindHebHebLBL.TabIndex = 8;
            this.FindHebHebLBL.Text = "Hebrew";
            // 
            // AddHebTB
            // 
            this.AddHebTB.Location = new System.Drawing.Point(128, 83);
            this.AddHebTB.Name = "AddHebTB";
            this.AddHebTB.Size = new System.Drawing.Size(111, 26);
            this.AddHebTB.TabIndex = 9;
            // 
            // AddEngTB
            // 
            this.AddEngTB.Location = new System.Drawing.Point(128, 117);
            this.AddEngTB.Name = "AddEngTB";
            this.AddEngTB.Size = new System.Drawing.Size(111, 26);
            this.AddEngTB.TabIndex = 9;
            // 
            // FindEngHebTB
            // 
            this.FindEngHebTB.Location = new System.Drawing.Point(394, 83);
            this.FindEngHebTB.Name = "FindEngHebTB";
            this.FindEngHebTB.Size = new System.Drawing.Size(111, 26);
            this.FindEngHebTB.TabIndex = 9;
            // 
            // FindEngEngTB
            // 
            this.FindEngEngTB.Enabled = false;
            this.FindEngEngTB.Location = new System.Drawing.Point(394, 117);
            this.FindEngEngTB.Name = "FindEngEngTB";
            this.FindEngEngTB.Size = new System.Drawing.Size(111, 26);
            this.FindEngEngTB.TabIndex = 9;
            // 
            // FindHebEngTB
            // 
            this.FindHebEngTB.Location = new System.Drawing.Point(624, 83);
            this.FindHebEngTB.Name = "FindHebEngTB";
            this.FindHebEngTB.Size = new System.Drawing.Size(111, 26);
            this.FindHebEngTB.TabIndex = 9;
            // 
            // FindHebHebTB
            // 
            this.FindHebHebTB.Enabled = false;
            this.FindHebHebTB.Location = new System.Drawing.Point(624, 117);
            this.FindHebHebTB.Name = "FindHebHebTB";
            this.FindHebHebTB.Size = new System.Drawing.Size(111, 26);
            this.FindHebHebTB.TabIndex = 9;
            // 
            // WordIB
            // 
            this.WordIB.Location = new System.Drawing.Point(545, 270);
            this.WordIB.Name = "WordIB";
            this.WordIB.Size = new System.Drawing.Size(208, 132);
            this.WordIB.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.WordIB.TabIndex = 10;
            this.WordIB.TabStop = false;
            // 
            // UploadPicBTN
            // 
            this.UploadPicBTN.Location = new System.Drawing.Point(45, 164);
            this.UploadPicBTN.Name = "UploadPicBTN";
            this.UploadPicBTN.Size = new System.Drawing.Size(80, 28);
            this.UploadPicBTN.TabIndex = 11;
            this.UploadPicBTN.Text = "Upload";
            this.UploadPicBTN.UseVisualStyleBackColor = true;
            this.UploadPicBTN.Click += new System.EventHandler(this.UploadPicBTN_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.UploadPicBTN);
            this.Controls.Add(this.WordIB);
            this.Controls.Add(this.FindHebHebTB);
            this.Controls.Add(this.FindEngEngTB);
            this.Controls.Add(this.AddEngTB);
            this.Controls.Add(this.FindHebEngTB);
            this.Controls.Add(this.FindEngHebTB);
            this.Controls.Add(this.AddHebTB);
            this.Controls.Add(this.FindHebHebLBL);
            this.Controls.Add(this.FindEngEngLBL);
            this.Controls.Add(this.FindHebEngLBL);
            this.Controls.Add(this.FindEngHebLBL);
            this.Controls.Add(this.AddEngLBL);
            this.Controls.Add(this.AddHebLBL);
            this.Controls.Add(this.FindHebLBL);
            this.Controls.Add(this.FindEngLBL);
            this.Controls.Add(this.AddWordLBL);
            this.Controls.Add(this.ShowDicBTN);
            this.Controls.Add(this.AddBTN);
            this.Controls.Add(this.FindHebBTN);
            this.Controls.Add(this.ClearBTN);
            this.Controls.Add(this.FindEngBTN);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.WordIB)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button FindEngBTN;
        private System.Windows.Forms.Button ClearBTN;
        private System.Windows.Forms.Button AddBTN;
        private System.Windows.Forms.Button ShowDicBTN;
        private System.Windows.Forms.Label AddWordLBL;
        private System.Windows.Forms.Label FindEngLBL;
        private System.Windows.Forms.Label FindHebLBL;
        private System.Windows.Forms.Label AddHebLBL;
        private System.Windows.Forms.Label AddEngLBL;
        private System.Windows.Forms.Label FindEngHebLBL;
        private System.Windows.Forms.Label FindEngEngLBL;
        private System.Windows.Forms.Label FindHebEngLBL;
        private System.Windows.Forms.Label FindHebHebLBL;
        private System.Windows.Forms.TextBox AddHebTB;
        private System.Windows.Forms.TextBox AddEngTB;
        private System.Windows.Forms.TextBox FindEngHebTB;
        private System.Windows.Forms.TextBox FindEngEngTB;
        private System.Windows.Forms.TextBox FindHebEngTB;
        private System.Windows.Forms.TextBox FindHebHebTB;
        private System.Windows.Forms.Button FindHebBTN;
        private System.Windows.Forms.PictureBox WordIB;
        private System.Windows.Forms.Button UploadPicBTN;
    }
}

