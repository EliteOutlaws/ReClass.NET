﻿using System;
using System.Diagnostics.Contracts;
using ReClassNET.Memory;

namespace ReClassNET.Debugger
{
	public interface IBreakpoint
	{
		IntPtr Address { get; }

		bool Set(RemoteProcess process);
		void Remove(RemoteProcess process);
	}

	[ContractClassFor(typeof(IBreakpoint))]
	internal abstract class IBreakpointContract : IBreakpoint
	{
		public IntPtr Address
		{
			get
			{
				throw new NotImplementedException();
			}
		}

		public void Remove(RemoteProcess process)
		{
			Contract.Requires(process != null);

			throw new NotImplementedException();
		}

		public bool Set(RemoteProcess process)
		{
			Contract.Requires(process != null);

			throw new NotImplementedException();
		}
	}
}
