using Microsoft.EntityFrameworkCore;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace LoginSystem.Models
{
    public class RegistrationContext: DbContext
    {
        public RegistrationContext(DbContextOptions<RegistrationContext> options): base(options)
        {

        }
        public DbSet<Registration> Registration { get; set; } 
        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Registration>().HasData(
                new Registration() { Username = "abc", Password = "admin", Email = "abc@gmail.com" }) ;
        }
    }
}
