namespace Lesson3
{
    partial class Form2
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
            this.ShowStudentsLBL = new System.Windows.Forms.Label();
            this.ExitBTN = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // ShowStudentsLBL
            // 
            this.ShowStudentsLBL.AutoSize = true;
            this.ShowStudentsLBL.Location = new System.Drawing.Point(132, 52);
            this.ShowStudentsLBL.Name = "ShowStudentsLBL";
            this.ShowStudentsLBL.Size = new System.Drawing.Size(114, 20);
            this.ShowStudentsLBL.TabIndex = 0;
            this.ShowStudentsLBL.Text = "ShowStudents";
            // 
            // ExitBTN
            // 
            this.ExitBTN.Location = new System.Drawing.Point(365, 346);
            this.ExitBTN.Name = "ExitBTN";
            this.ExitBTN.Size = new System.Drawing.Size(91, 41);
            this.ExitBTN.TabIndex = 1;
            this.ExitBTN.Text = "Exit";
            this.ExitBTN.UseVisualStyleBackColor = true;
            this.ExitBTN.Click += new System.EventHandler(this.ExitBTN_Click);
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.ExitBTN);
            this.Controls.Add(this.ShowStudentsLBL);
            this.Name = "Form2";
            this.Text = "Form2";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label ShowStudentsLBL;
        private System.Windows.Forms.Button ExitBTN;
    }
}